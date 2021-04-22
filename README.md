# Embedded Systems - Home Automation Servers

The objective of this application is to control an simulated environment for home automation. It is a college project from the discipline of Fundamentals of Embedded Systems. The complete description is here [project description](https://gitlab.com/fse_fga/projetos_2020_2/projeto-2-2020.2).

## Running

### Central Server (Run first)

```bash
# Clone the repository:
git clone --recursive https://github.com/silvasara/embedded-systems-2.git

# `cd` into central server's dir
cd embedded-systems-2/central-server

# Run
python3 main.py
```

### Distributed Server

```bash
# In another terminal, `cd` into distributed server's dir
cd embedded-systems-2/distributed-server

# Build distributed server
make

# Run
make run
```

### Menu
![image](https://user-images.githubusercontent.com/30883179/115639775-d2a56100-a2eb-11eb-9672-eb6c322d75d2.png)
