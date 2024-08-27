import json

# Load the JSON data
with open('data.json') as file:
    data = json.load(file)

# Extract real data (Table 0)
real_data = data["Table 0"]

# Initialize a dictionary to store the positions from Table 0
real_positions = {}

# Store the position of each team in the real data
for row in real_data:
    real_positions[row['Club']] = row['Position']

# Initialize a dictionary to store the count of times each team is in their real position in simulations
simulation_position_counts = {team: 0 for team in real_positions.keys()}

# Iterate over simulation tables (Tables 1 to 10)
for i in range(1, 11):
    table_key = f"Table {i}"
    table = data[table_key]
    
    # Compare each team's position in the simulation to their position in the real data
    for row in table:
        team_name = row['Club'] if 'Club' in row else row['Team']
        if team_name in real_positions:
            if row['Position'] == real_positions[team_name]:
                simulation_position_counts[team_name] += 1

# Calculate percentages for each team
simulation_position_percentages = {team: (count / 10) * 100 for team, count in simulation_position_counts.items()}

# Print the results
print("Comparison of Simulation Positions with Real Data:")
for team, percentage in simulation_position_percentages.items():
    print(f"{team} was in position {real_positions[team]} {percentage}% of the time.")