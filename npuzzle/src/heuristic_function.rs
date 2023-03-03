fn check_if_is_in_line(nb: &i32, puzzle: &Vec<i32>, goal: &Vec<i32>, size: &i32) -> bool {
	let puzzle_index: i32 = puzzle.iter().position(|&x| x == *nb).unwrap().try_into().unwrap();
	let goal_index: i32 = goal.iter().position(|&x| x == *nb).unwrap().try_into().unwrap();

	if puzzle_index / size == goal_index / size {
		return true;
	}
	return false;
}

fn check_if_is_in_coloumn(nb: &i32, puzzle: &Vec<i32>, goal: &Vec<i32>, size: &i32) -> bool {
	let puzzle_index: i32 = puzzle.iter().position(|&x| x == *nb).unwrap().try_into().unwrap();
	let goal_index: i32 = goal.iter().position(|&x| x == *nb).unwrap().try_into().unwrap();

	if puzzle_index % size == goal_index % size {
		return true;
	}
	return false;
}

pub fn linear_cost(puzzle: &Vec<i32>, goal: &Vec<i32>, size: &i32) -> i32 {
	let mut cost: i32 = manhattan_cost(puzzle, goal, size);

	for nb in puzzle {
		if *nb == 0 {
			continue;
		}
		if check_if_is_in_line(nb, puzzle, goal, size) {
			let nb_index: usize = puzzle.iter().position(|&x| x == *nb).unwrap();
			let mut check_index: usize = puzzle.iter().position(|&x| x == *nb).unwrap() / *size as usize;
			let start_index = check_index;
			while check_index < start_index + *size as usize {
				if puzzle[check_index] != 0 && 
				check_if_is_in_line(&puzzle[check_index], puzzle, goal, size) &&
				check_index < nb_index &&
				goal.iter().position(|&x| x == puzzle[check_index]).unwrap() > goal.iter().position(|&x| x == puzzle[nb_index]).unwrap() {
						cost += 1;
				}
				check_index += 1;
			}
		}
		if check_if_is_in_coloumn(nb, puzzle, goal, size) {
			let nb_index: usize = puzzle.iter().position(|&x| x == *nb).unwrap();
			let mut check_index: usize = puzzle.iter().position(|&x| x == *nb).unwrap() / *size as usize;
			while check_index < (size * size) as usize {
				if puzzle[check_index] != 0 && 
				check_if_is_in_coloumn(&puzzle[check_index], puzzle, goal, size) &&
				check_index < nb_index &&
				goal.iter().position(|&x| x == puzzle[check_index]).unwrap() > goal.iter().position(|&x| x == puzzle[nb_index]).unwrap() {
						cost += 1;
				}
				check_index += *size as usize;
			}
		}
	}
	cost
}

pub fn manhattan_cost(puzzle: &Vec<i32>, goal: &Vec<i32>, size: &i32) -> i32 {
	let mut cost: i32 = 0;
	for nb in puzzle {
		if *nb == 0 {
			continue;
		}
		let puzzle_index: i32 = puzzle.iter().position(|&x| x == *nb).unwrap().try_into().unwrap();
		let goal_index: i32 = goal.iter().position(|&x| x == *nb).unwrap().try_into().unwrap();
		cost += ((puzzle_index % size) - (goal_index % size)).abs();
		cost += ((puzzle_index / size) - (goal_index / size)).abs();
	}

	cost
}

pub fn hamming_cost(puzzle: &Vec<i32>, goal: &Vec<i32>) -> i32 {
	let mut cost:i32 = 0;
	for nb in puzzle {
		if *nb == 0 {
			continue ;
		}
		if puzzle.iter().position(|&x| x == *nb).unwrap() != 
			goal.iter().position(|&x| x == *nb).unwrap() {
			cost += 1;
		}
	}
	cost
}