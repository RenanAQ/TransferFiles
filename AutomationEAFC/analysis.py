import json

combined_data = {
    "Table1": [
        # JSON data from the first table
    ],
    "Table2": [
        # JSON data from the second table
    ]
}

with open('data.json', 'w') as f:
    json.dump(combined_data, f, indent=4)