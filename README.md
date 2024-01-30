# 42 Philosophers Project

## Description
The "42 Philosophers" project is a C implementation of the classic dining philosophers problem— a renowned synchronization challenge in computer science.
In this simulation, a specified number of philosophers sit around a dining table, alternating between thinking and eating.

The project is written in C and places a strong emphasis on preventing deadlocks. It achieves this through the strategic use of mutexes and threads to manage access to shared resources,
specifically the forks on the dining table. The goal is to provide a robust solution that ensures proper synchronization, showcasing the application of fundamental concurrency concepts in a multithreaded environment.

## Key Features
- C implementation of the dining philosophers problem.
- Prevention of deadlocks using mutexes and threads.
- Dynamic simulation with adjustable parameters: number of philosophers, time to die, time to eat, time to sleep, and number of times each philosopher must eat.

## How to Run
1. Clone the repository.
2. Compile the project using the provided Makefile.
3. Run the executable with specified parameters (number of philosophers, time intervals).

## Contributing
Contributions are welcome! Feel free to report issues, suggest improvements, or submit pull requests.
