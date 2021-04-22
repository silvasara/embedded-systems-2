import curses

class Menu:
    choices = [
        ("1 - Ligar/Desligar Lâmpada 01 (Cozinha)", "lamp_1"),
        ("2 - Ligar/Desligar Lâmpada 02 (Sala)", "lamp_2"),
        ("3 - Ligar/Desligar Lâmpada 03 (Quarto 01)", "lamp_3"),
        ("4 - Ligar/Desligar Lâmpada 04 (Quarto 02)", "lamp_4"),
        ("5 - Ligar/Desligar Ar-Condicionado 01 (Quarto 01)", "air_cond_1"),
        ("6 - Ligar/Desligar Ar-Condicionado 02 (Quarto 02)", "air_cond_2"),
    ]

    def __init__(self, stdscr):
        self.highlight = 1
        max_y, max_x = stdscr.getmaxyx()
        self.window = curses.newwin(max_y, int(max_x / 2), 0, 0)
        self.choice = ''
        self.window.keypad(True)
        self.window.box()
        self.window.refresh()

    def get_user_input(self):
        self.choice = ''
        self.show_menu()
        while True:
            c = self.window.getch()
            if c == curses.KEY_UP:
                if self.highlight == 1:
                    self.highlight = len(self.choices)
                else:
                    self.highlight -= 1
            elif c == curses.KEY_DOWN:
                if self.highlight == len(self.choices):
                    self.highlight = 1
                else:
                    self.highlight += 1
            elif c == 10:
                    self.choice = self.choices[self.highlight - 1][1]

            self.show_menu()

            if self.choice != '':
                break

        return self.choice

    def show_menu(self):
        x = 3
        y = 4
        self.window.clear()
        self.window.box()
        self.window.addstr(1, 1, "Utilize as setas para navegar entre as opções.")
        self.window.addstr(2, 1, "Pressione Enter para selecionar uma opção.")
        self.window.addstr(3, 1, "Para sair, pressione Ctrl+c.")
        for i, (choice, key) in enumerate(self.choices):
            if self.highlight == i + 1:
                self.window.addstr(y, x, choice, curses.A_REVERSE)
            else:
                self.window.addstr(y, x, choice, curses.A_NORMAL)
            y += 1
        self.window.refresh()

    def show_info(self, message, y=1, x=1):
        self.window.clear()
        self.window.addstr(y, x, message)
        self.window.box()
        self.window.refresh()


class Output:
    def __init__(self, stdscr):
        max_y, max_x = stdscr.getmaxyx()
        self.window = curses.newwin(max_y, int(max_x / 2), 0, int(max_x / 2))
        self.window.box()
        self.window.refresh()

    def show_data(self, data):
        self.window.clear()
        self.window.box()
        self.window.addstr(2, 2, f'Temperatura:                              {data.get("temperature")} °C')
        self.window.addstr(3, 2, f'Umidade:                                  {data.get("humidity")} %')
        self.window.addstr(5, 2, f'Sensor de Presença 01 (Sala):             {data.get("living_room")}')
        self.window.addstr(6, 2, f'Sensor de Presença 02 (Cozinha):          {data.get("kitchen")}')
        self.window.addstr(7, 2, f'Sensor Abertura 01 (Porta Cozinha):       {data.get("kitchen_door")}')
        self.window.addstr(8, 2, f'Sensor Abertura 02 (Janela Cozinha):      {data.get("kitchen_window")}')
        self.window.addstr(9, 2, f'Sensor Abertura 03 (Porta Sala):          {data.get("living_room_door")}')
        self.window.addstr(10, 2, f'Sensor Abertura 04 (Janela Sala):         {data.get("living_room_window")}')
        self.window.addstr(11, 2, f'Sensor Abertura 05 (Janela Quarto 01):    {data.get("room_window_01")}')
        self.window.addstr(12, 2, f'Sensor Abertura 05 (Janela Quarto 02):    {data.get("room_window_02")}')
        self.window.addstr(14, 2, f'Lâmpada 01 (Cozinha):                     {data.get("lamp_01")}')
        self.window.addstr(15, 2, f'Lâmpada 02 (Sala):                        {data.get("lamp_02")}')
        self.window.addstr(16, 2, f'Lâmpada 03 (Quarto 01):                   {data.get("lamp_03")}')
        self.window.addstr(17, 2, f'Lâmpada 04 (Quarto 02):                   {data.get("lamp_04")}')
        self.window.addstr(18, 2, f'Ar-Condicionado 01 (Quarto 01):           {data.get("air_cond_01")}')
        self.window.addstr(19, 2, f'Ar-Condicionado 02 (Quarto 02):           {data.get("air_cond_02")}')
        self.window.refresh()

