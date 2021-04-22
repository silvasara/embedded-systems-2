# Embedded Systems - Home Automation Servers

The objective of this application is to control an simulated environment for home automation. It is a college project from the discipline of Fundamentals of Embedded Systems. The complete description is here [project description](https://gitlab.com/fse_fga/projetos_2020_2/projeto-2-2020.2).

## Building

The code was developed and tested in two Raspberries Pi.

### External dependencies

There is a dependency that was not cloned with this repository:
* [Wiring Pi](http://wiringpi.com/download-and-install/)


1. Clone the repository:

``` bash
git clone --recursive https://github.com/silvasara/embedded-systems-2.git
cd embedded-systems-2
```

2. `cd` into distributed server's dir and build it:

``` bash
cd distributed-server
```
3. Build distributed server
``` bash
make
```

## Running
4. Run the central server:
```bash
python3 central-server/main.py
```

5. In another terminal run the distributed server:
``` bash
cd distributed-server/
make run
```
### Menu
![image](https://user-images.githubusercontent.com/30883179/115639775-d2a56100-a2eb-11eb-9672-eb6c322d75d2.png)
