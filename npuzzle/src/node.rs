use std::fmt;

use crate::{settings::Settings, heuristic_function::{linear_cost, hamming_cost, manhattan_cost}};

struct MoveTo {
	up: i32,
	down: i32,
	left: i32,
	right: i32,
}

impl MoveTo {
	pub fn new(puzzle_size: &i32) -> MoveTo{
		let move_to = MoveTo {
			up: *puzzle_size,
			down: *puzzle_size * -1,
			left: 1,
			right: -1,
		};
		move_to
	}
}

#[derive(Clone)]
pub struct Node {
	pub index: i32,
	pub g_cost: i32,
	pub h_cost: i32,
	pub f_cost: i32,
	pub puzzle: Vec<i32>,
	pub puzzle_size: i32,
}

impl Node {
	pub fn new(settings: &Settings, goal: &Vec<i32>, index: i32, g_cost: i32, puzzle: Vec<i32>) -> Node {
		let mut new_node = Node {
			index: index,
			g_cost: g_cost * settings.g_cost_multi,
			h_cost: 0,
			f_cost: 0,
			puzzle: puzzle,
			puzzle_size: settings.size,
		};

		match settings.heuristic_fn.as_str() {
			"linear" => new_node.h_cost = linear_cost(&new_node.puzzle, goal, &settings.size) * settings.h_cost_multi,
			"manhattan" => new_node.h_cost = manhattan_cost(&new_node.puzzle, goal, &settings.size) * settings.h_cost_multi,
			_ => new_node.h_cost = hamming_cost(&new_node.puzzle, goal) * settings.h_cost_multi,
		}

		new_node.f_cost = new_node.g_cost + new_node.h_cost;
		new_node
	}

	fn new_neighbour(&self, settings: &Settings, goal: &Vec<i32>, move_to: &i32) -> Node {
		let mut next_puzzle: Vec<i32> = self.puzzle.clone();
		next_puzzle.swap(self.index as usize, (self.index + move_to) as usize);
		let new_neighbour = Node::new(settings, goal, self.index + move_to, self.g_cost + 1, next_puzzle);
		new_neighbour
	}

	pub fn get_neighbours(&self, settings: &Settings, goal: &Vec<i32>) -> Vec<Node> {
		let move_to = MoveTo::new(&settings.size);
		let mut neighbours: Vec<Node> = Vec::new();
		if self.index > settings.size {
			neighbours.push(self.new_neighbour(settings, goal, &move_to.down));
		}
		if self.index < settings.size * settings.size - settings.size {
			neighbours.push(self.new_neighbour(settings, goal, &move_to.up));
		}
		if (self.index + 1) % settings.size != 0 {
			neighbours.push(self.new_neighbour(settings, goal, &move_to.left));
		}
		if self.index % settings.size != 0 {
			neighbours.push(self.new_neighbour(settings, goal, &move_to.right));
		}
		neighbours
	}
}

impl fmt::Display for Node {
	fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
		let u_size = self.puzzle_size as usize;
		let mut i = 0;

		write!(f, "Display node:\nindex: {} | g_cost: {} | h_cost: {} | f_cost: {} | puzzle:\n", self.index, self.g_cost, self.h_cost, self.f_cost)?;

		for nb in self.puzzle.iter() {
			if i != 0 && i % u_size == 0 {
				write!(f, "\n")?;
			}
			write!(f, "{:3} ", nb)?;
			i += 1;
		}
		write!(f, "\n")
	}
}

impl Eq for Node {}

impl PartialEq for Node {
	fn eq(&self, other: &Self) -> bool {
		self.f_cost == other.f_cost
	}
}

impl PartialOrd for Node {
	fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
		Some(self.cmp(other))
	}
}

impl Ord for Node {
	fn cmp(&self, other: &Self) -> std::cmp::Ordering {
		self.f_cost.cmp(&other.f_cost).reverse()
	}
}