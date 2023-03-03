use crate::a_star::launch_a_star;

mod settings;
mod puzzle_fct;
mod a_star;
mod node;
mod heuristic_function;

fn main() {
    let settings = settings::Settings::new().unwrap_or_else(|err| {
		eprintln!("Error during settings initialization: {}", err);
		std::process::exit(1);
	});
	println!("{}", settings);
	launch_a_star(&settings);
}
