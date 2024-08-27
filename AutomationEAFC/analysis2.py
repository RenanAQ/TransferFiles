import json

# Load the JSON data
with open('data.json') as file:
    data = json.load(file)

# Extract real data (Table 0)
real_data = data["Table 0"]

# Get the last 3 teams from the real data
bottom_3_teams = [row['Club'] for row in real_data if row['Position'] >= 18]

# Initialize counters for group comparison
bottom_3_correct_position_count = 0

# Iterate over simulation tables (Tables 1 to 10)
for i in range(1, 11):
    table_key = f"Table {i}"
    table = data[table_key]
    
    # Get the bottom 3 teams in the current simulation table
    sim_bottom_3_teams = [row['Club'] if 'Club' in row else row['Team'] for row in table if row['Position'] >= 18]
    
    # Check if all bottom 3 teams from the real data are in the bottom 3 in the simulation
    if all(team in sim_bottom_3_teams for team in bottom_3_teams):
        bottom_3_correct_position_count += 1

# Calculate the percentage
bottom_3_correct_position_percentage = (bottom_3_correct_position_count / 10) * 100

# Print the results
print("Comparison of Bottom 3 Teams in Simulations:")
print(f"The last 3 teams from the real data were all in the last 3 positions {bottom_3_correct_position_percentage}% of the time across the simulations.")