use rand::distributions::{Distribution, Standard};
use rand::Rng;

#[derive(Debug, PartialEq)]
enum MovePuzzleRandomizer {
	Up,
	Down,
	Left,
	Right,
}

impl Distribution<MovePuzzleRandomizer> for Standard {
    fn sample<R: Rng + ?Sized>(&self, rng: &mut R) -> MovePuzzleRandomizer {
        match rng.gen_range(0..4) {
            0 => MovePuzzleRandomizer::Up,
            1 => MovePuzzleRandomizer::Down,
            2 => MovePuzzleRandomizer::Left,
            _ => MovePuzzleRandomizer::Right,
        }
    }
}

pub fn generate_goal(size: &i32) -> Vec<i32> {
	let puzzle_size = (*size) * (*size);
	let mut goal = std::iter::repeat(-1).take(puzzle_size as usize).collect::<Vec<_>>();

	let mut x: i32 = 0;
	let mut ix: i32 = 1;
	let mut y: i32 = 0;
	let mut iy: i32 = 0;
	let mut current: i32 = 1;
	loop {
		goal[(x + (size * y)) as usize] = current;
		if current == 0 {
			break ;
		}
		current += 1;
		if x + ix == *size || x + ix < 0 || (ix != 0 && goal[(x + ix + (y * (*size))) as usize] != -1) {
			iy = ix;
			ix = 0;
		}
		else if y + iy == *size || y + iy < 0 || (iy != 0 && goal[(x + ((y + iy) * size)) as usize] != -1) {
			ix = -iy;
			iy = 0;
		}
		x += ix;
		y += iy;
		if current == size * size {
			current = 0;
		}
	}
	goal
}

pub fn generate_random_puzzle(size: &i32) -> Vec<i32> {
	let puzzle_size = (*size) * (*size);
	let mut random_puzzle = std::iter::repeat(-1).take(puzzle_size as usize).collect::<Vec<_>>();

	let mut x: i32 = 0;
	let mut ix: i32 = 1;
	let mut y: i32 = 0;
	let mut iy: i32 = 0;
	let mut current: i32 = 1;
	loop {
		random_puzzle[(x + (size * y)) as usize] = current;
		if current == 0 {
			break ;
		}
		current += 1;
		if x + ix == *size || x + ix < 0 || (ix != 0 && random_puzzle[(x + ix + (y * (*size))) as usize] != -1) {
			iy = ix;
			ix = 0;
		}
		else if y + iy == *size || y + iy < 0 || (iy != 0 && random_puzzle[(x + ((y + iy) * size)) as usize] != -1) {
			ix = -iy;
			iy = 0;
		}
		x += ix;
		y += iy;
		if current == size * size {
			current = 0;
		}
	}
	for _i in 0..1000 {
		let rand_move: MovePuzzleRandomizer = rand::random();
		if rand_move == MovePuzzleRandomizer::Up && y != *size - 1 {
			random_puzzle.swap((x + (y * (*size))) as usize, (x + ((y + 1) * (*size))) as usize);
			y += 1;
		}
		else if rand_move == MovePuzzleRandomizer::Down && y != 0 {
			random_puzzle.swap((x + (y * (*size))) as usize, (x + ((y - 1) * (*size))) as usize);
			y -= 1;
		}
		else if rand_move == MovePuzzleRandomizer::Left && x != *size - 1 {
			random_puzzle.swap((x + (y * (*size))) as usize, (x + 1 + (y * (*size))) as usize);
			x += 1;
		}
		else if rand_move == MovePuzzleRandomizer::Right && x != 0 {
			random_puzzle.swap((x + (y * (*size))) as usize, (x - 1 + (y * (*size))) as usize);
			x -= 1;
		}
	}
	random_puzzle
}

pub fn print_puzzle(puzzle: &Vec<i32>, size: &i32) {
	let u_size = *size as usize;
	let mut i = 0;
	for nb in puzzle.iter() {
		if i != 0 && i % u_size == 0 {
			println!("");
		}
		print!("{:3} ", nb);
		i += 1;
	}
	println!("");
}