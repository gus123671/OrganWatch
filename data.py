import csv  
import names
import random

# Author: Augustus Rodriguez
# Email: augustusrodriguez007@gmail.com
# Github: gus123671
# Created: 11/23/22

header = ["name", "age", "organ", "location", "priority"]
organs = ["Kidney", "Liver", "Lung", "Heart"]
locations = ["Southeast", "Northeast", "Southwest", "Northwest", "Midwest"]

with open("data.csv", "w", encoding="UTF8", newline='') as f:
    writer = csv.writer(f)

    # write the header
    writer.writerow(header)

    # write the data
    for i in range(100000):
        name = names.get_full_name()
        age = random.randint(1, 200)
        organ = random.choice(organs)
        location = random.choice(locations)
        row = [name, age, organ, location]
        writer.writerow(row)



