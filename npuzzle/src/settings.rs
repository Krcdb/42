use std::{env, fmt};
use std::fs::File;
use std::io::{BufReader, BufRead};
use std::path::Path;

use crate::puzzle_fct::{generate_random_puzzle};

#[derive(Debug)]
pub struct Settings {
	pub mode: String,
	pub file_name: String,
	pub heuristic_fn: String,
	pub size: i32,
	pub g_cost_multi: i32,
	pub h_cost_multi: i32,
	pub puzzle: Vec<i32>,
	pub light_result_display: bool,
	pub full_display: bool,
}

impl fmt::Display for Settings {
	fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
		let u_size = self.size as usize;
		let mut i = 0;

		write!(f, "Start solving n-puzzle with this settings:\nAlgo: A*\nMode: {}\nHeuristic function: {}\nStarting puzzle:\n", self.mode, self.heuristic_fn)?;

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

impl Settings {
	fn file_to_settings_and_check(&mut self) -> Result<(), String> {
		let path = Path::new(&self.file_name);
    	let display = path.display();
		let mut nb_in_row = 0;
		let mut nb_row = 0;
		let mut puzzle_found: bool = false;
    	
		let file = match File::open(&path) {
    	    Err(why) => {return Err(format!("couldn't open {}: {}", display, why))}
    	    Ok(file) => file,
    	};
    	
		let reader = BufReader::new(file);
		//Read each line
    	for line in reader.lines() {
    	    match line {
    	        Ok(line) => {
					let mut size_found: bool = false;
					let mut row_found: bool = false;
					if nb_in_row != 0 && nb_in_row != self.size {
						return Err(format!("bad input format: row must have {} number, found a {} number row", self.size, nb_in_row));
					}
					nb_in_row = 0;
					if line.len() == 0 {
						if puzzle_found {
							break ;
						}
						continue ;
					}
					let split_line: Vec<_> = line.split_whitespace().collect();
					for word in split_line {
						if word.starts_with("#") {
							break ;
						}
						else if size_found {
							return Err(format!("bad input file format: size must be specified before the puzzle"));
						}
						//Check if all digit
						else if !word.bytes().all(|c| c.is_ascii_digit()) {
							return Err(format!("bad input file format: found this {}", word));
						}
						//Get the size
						else if self.size == 0 {
							match word.parse::<i32>() {
								Ok(n) =>  {
									self.size = n;
									size_found = true;
								}
								Err(err) => { return Err(err.to_string()) }
							}
						}
						//Push the parsed number in the puzzle
						else {
							match word.parse::<i32>() {
								Ok(n) =>  {
									if self.puzzle.contains(&n) {
										return Err(format!("bad input file format: {} is already in the puzzle", n))
									}
									self.puzzle.push(n);
									nb_in_row += 1;
									puzzle_found = true;
									if !row_found {
										row_found = true;
										nb_row += 1;
									}
								}
								Err(err) => { return Err(err.to_string()) }
							}
						}
					}
    	        }
    	        Err(e) => { return Err(format!("ERROR: {}", e))}
    	    }
    	}
		//Check the size of the puzzle
		if nb_row != self.size {
			return Err(format!("bad input format: must have {} row, found {} row", self.size, nb_row));
		}
		for i in 0..(self.size * self.size) {
			if !self.puzzle.contains(&i) {
				return Err(format!("bad input file format: {} is missing", i))
			}
		}
		Ok(())
	}

    pub fn new() -> Result<Settings, String> {
		let args: Vec<String> = env::args().skip(1).collect();
		let mut mode_already_found: bool = false;
		let mut heuristic_already_found: bool = false;
		let mut display_already_found: bool = false;

		let mut settings = Settings {
			mode: "normal".to_string(),
			file_name: "".to_string(),
			heuristic_fn: "linear".to_string(),
			size: 0,
			g_cost_multi: 1,
			h_cost_multi: 1,
			puzzle: Vec::new(),
			light_result_display: false,
			full_display: false,
		};

		let mut b_file_found: bool = false;
		//Parse args
		for arg in args.iter() {
			if arg.starts_with("--") {
				if (arg == "--normal" || arg == "--greedy" || arg == "--uniform") && !mode_already_found {
					settings.mode = arg[2..].to_string();
					mode_already_found = true;
				} else if (arg == "--hamming" || arg == "--manhattan" || arg == "--linear") && !heuristic_already_found {
					settings.heuristic_fn = arg[2..].to_string();
					heuristic_already_found = true;
				} else if arg == "--light-display" && !display_already_found {
					settings.light_result_display = true;
					display_already_found = true;
				} else if arg == "--full-display" && !display_already_found {
					settings.full_display = true;
					display_already_found = true;
				} else {
					return Err(format!("Invalid argument : {}", arg))
				}
			} else {
				if b_file_found {
					return Err(format!("Too many file name, already have {}, don't need {}", settings.file_name, arg))
				}
				b_file_found = true;
				settings.file_name = arg.to_string();
			}
		}
		if settings.file_name == "" {
			settings.size = 3;
			settings.puzzle = generate_random_puzzle(&settings.size);
		}
		else {
			match settings.file_to_settings_and_check() {
				Err(err) => { return Err(err) },
				Ok(_) => (),
			}
		}
		match settings.mode.as_str() {
			"greedy" => settings.g_cost_multi = 0,
			"uniform" => settings.h_cost_multi = 0,
			_ => (),
		}
		Ok(settings)
	}
}