# Author: Augustus Rodriguez
# Email: augustusrodriguez007@gmail.com
# Github: gus123671
# Created: 11/23/22

import csv  
import names
import random

header = ["name", "age", "organ", "location", "urgency"]
organs = ["Kidney", "Liver", "Lung", "Heart"]
locations = ["Southeast", "Northeast", "Southwest", "Northwest", "Midwest"]

with open("recipients.csv", "w", encoding="UTF8", newline='') as f:
    writer = csv.writer(f)

    # write the header
    writer.writerow(header)

    # write the data
    for i in range(100000):
        name = names.get_full_name()
        age = random.randint(1, 100)
        organ = random.choice(organs)
        location = random.choice(locations)
        urgency = random.randint(1, 5)
        row = [name, age, organ, location, urgency]
        writer.writerow(row)

header2 = ["name", "age", "organ", "location"]


with open("donors.csv", "w", encoding="UTF8", newline='') as f:
    writer = csv.writer(f)

    writer.writerow(header2)

    for i in range(20000):
        name = names.get_full_name()
        age = random.randint(1, 118)
        organ = random.choice(organs)
        location = random.choice(locations)
        row = [name, age, organ, location]
        writer.writerow(row)