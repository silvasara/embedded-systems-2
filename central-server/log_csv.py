import csv
import datetime


def create_csv():
    filename = "log.csv"
    csv_file = open(filename, 'w')

    fields = [
        "date",
        "time",
        "lamp_01",
        "lamp_02",
        "lamp_03",
        "lamp_04",
        "air_cond_01",
        "air_cond_02",
        "living_room",
        "kitchen",
        "kitchen_door",
        "kitchen_window",
        "living_room_door",
        "living_room_window",
        "room_window_01",
        "room_window_02",
        "temperature",
        "humidity",
    ]

    writer = csv.DictWriter(csv_file, fieldnames=fields)
    writer.writeheader()

    return csv_file, writer


def write_rows(writer, data):
    now = datetime.datetime.now()
    data['date'] = f'{now.day}/{now.month}/{now.year}'
    data['time'] = f'{now.hour}:{now.minute}:{now.second}'

    writer.writerows([data])


def save_csv(csv_file):
    csv_file.close()
