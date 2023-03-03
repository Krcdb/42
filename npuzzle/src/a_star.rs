use std::collections::{BinaryHeap, HashMap};

use crate::{settings::{Settings}, puzzle_fct::{generate_goal, print_puzzle}, node::Node};

fn rebuild_path(start: Vec<i32>, goal: Vec<i32>, parent_map: HashMap<Vec<i32>, Vec<i32>>) -> Vec<Vec<i32>> {
	let mut path: Vec<Vec<i32>> = vec![goal.clone()];
	let mut current:Vec<i32> = parent_map.get(&goal).unwrap().to_vec();

	while current != start {
		path.push(current.clone());
		current = parent_map.get(&current).unwrap().to_vec();
	}
	path.push(start);
	path.reverse();
	path
}

fn print_result(settings: &Settings, path: Vec<Vec<i32>>, total_iteration: i32, max_open_set_size: i32) {
	let mut prev_index: i32 = path[0].iter().position(|&x| x == 0).unwrap().try_into().unwrap();
	let mut current_index: i32;
	let mut nb_moves: usize = 0;
	
	if settings.full_display {
		println!("Start :");
		print_puzzle(&path[0], &settings.size);
		println!("");
	}
	for current in path{
		current_index = current.iter().position(|&x| x == 0).unwrap().try_into().unwrap();
		if current_index == prev_index {
			continue ;
		}
		let move_to: String = match current_index - prev_index {
			x if x == -settings.size => "UP".to_string(),
			x if x == settings.size => "DOWN".to_string(),
			x if x == -1 => "LEFT".to_string(),
			x if x == 1 => "RIGHT".to_string(),
			_ => "".to_string(),
		};
		if settings.light_result_display {
			if nb_moves != 1 && nb_moves % 16 == 0 {
				println!("");
			}
			print!("{}, ", move_to);
		}
		else if settings.full_display {
			println!("move nb {:3} | {} :", nb_moves, move_to);
			print_puzzle(&current, &settings.size);
			println!()
		}
		nb_moves += 1;
		prev_index = current_index;
	}
	if settings.light_result_display {
		println!("");
	}
	println!("\nResult found:\nTotal states selected: {}\nMaximum number of states in memory: {}\nNumber of moves: {}\n", total_iteration, max_open_set_size, nb_moves);
}

pub fn launch_a_star(settings: &Settings) {
	let mut total_iteration: i32 = 0;
	let mut max_open_set_size: i32 = 1;
	
	let goal:Vec<i32> = generate_goal(&settings.size);
	let start: Node = Node::new(settings, &goal, settings.puzzle.iter().position(|&x| x == 0).unwrap().try_into().unwrap(), 0, settings.puzzle.clone());
	let mut open_set: BinaryHeap<Node> = BinaryHeap::new();
	let mut open_set_check: HashMap<Vec<i32>, bool> = HashMap::new();
	
	let mut parent_map: HashMap<Vec<i32>, Vec<i32>> = HashMap::new();
	let mut best_cost_to_node: HashMap<Vec<i32>, i32> = HashMap::new();

	let mut closed_set: HashMap<Vec<i32>, bool> = HashMap::new();

	open_set_check.insert(start.puzzle.clone(), true);
	open_set.push(start);

	while let Some(current_node) = open_set.pop() {
		//print!("Current node | {}", current_node);
		total_iteration += 1;
		closed_set.insert(current_node.puzzle.clone(), true);
		open_set_check.remove_entry(&current_node.puzzle);
		
		/*if total_iteration == 10 {
			break;
		}*/
		if current_node.puzzle == goal {
			print_result(settings, rebuild_path(settings.puzzle.clone(), goal, parent_map), total_iteration, max_open_set_size);
			return ;
		}
		for next_node in current_node.get_neighbours(settings, &goal) {
			//if node is in closed_set continue
			if closed_set.contains_key(&next_node.puzzle) {
				continue;
			}
			//if not in open_set at it
			else if !open_set_check.contains_key(&next_node.puzzle) {
				parent_map.insert(next_node.puzzle.clone(), current_node.puzzle.clone());
				best_cost_to_node.insert(next_node.puzzle.clone(), next_node.f_cost);
				open_set_check.insert(next_node.puzzle.clone(), true);
				open_set.push(next_node);
			}
			//if in open_set, check if it has a better cost and if so, update it
			else if open_set_check.contains_key(&next_node.puzzle) {
				let current_best_cost_to_node = best_cost_to_node.get_mut(&next_node.puzzle).unwrap();
				if next_node.f_cost < *current_best_cost_to_node {
					*current_best_cost_to_node = next_node.f_cost;
					*parent_map.get_mut(&next_node.puzzle).unwrap() = current_node.puzzle.clone();
				}
			}
		}
		//check max open_set size
		if open_set_check.len() as i32 > max_open_set_size {
			max_open_set_size = open_set_check.len() as i32;
		}
	}
	//No solution
	println!("This puzzle is unsolvable\nTotal states selected: {}\nMaximum number of states in memory: {}\n", total_iteration, max_open_set_size);
}
