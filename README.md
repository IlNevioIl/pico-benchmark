# RPi Pico Benchmark

RPI Pico benchmark featuring a score system.

![alt text](https://github.com/IlNevioIl/pico-benchmark/blob/main/pico.PNG)

## How to use

1. Download and install [Putty](https://www.putty.org/).
2. Download the [Benchmark.uf2](https://github.com/IlNevioIl/pico-benchmark/releases) file and drag it on you Pico.
3. Find the `COM Port` the Pico is connected to. (Open the Windows device manager and look at the Com Ports. For me it was `COM5`)
4. Open `Putty` and select `serial` as the `connection type`.
5. For the `Serial line` select the `com port` your pico is connected to but `dont` click `OPEN` yet.
6. Reboot your pico by plugging out the cable and plugging it back in.
7. Now click `Open` inside `Putty`. (You have 5 seconds before the benchmark starts)
8. Have fun :)

## How does the benchmark and scoresystem work?
The benchmark is a pretty unefficient 0(n) bubble sort. Its sorting a 10.000 array of numbers 10.000 times.
The score is basically how many milliseconds your pico needs to sort the 10.000 numbers.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

Note: If something in the bubble sort is changed, the score will be different because we have less or more tasks then before.

## License
[MIT](https://choosealicense.com/licenses/mit/)
