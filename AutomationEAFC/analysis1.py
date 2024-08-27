import json

# Load the JSON data
with open('data.json') as file:
    data = json.load(file)

# Extract real data (Table 0)
real_data = data["Table 0"]

# Get the top 6 teams from the real data
top_6_teams = [row['Club'] for row in real_data if row['Position'] <= 6]

# Initialize counters for group comparison
top_6_correct_position_count = 0

# Iterate over simulation tables (Tables 1 to 10)
for i in range(1, 11):
    table_key = f"Table {i}"
    table = data[table_key]
    
    # Get the top 6 teams in the current simulation table
    sim_top_6_teams = [row['Club'] if 'Club' in row else row['Team'] for row in table if row['Position'] <= 6]
    
    # Check if all top 6 teams from the real data are in the top 6 in the simulation
    if all(team in sim_top_6_teams for team in top_6_teams):
        top_6_correct_position_count += 1

# Calculate the percentage
top_6_correct_position_percentage = (top_6_correct_position_count / 10) * 100

# Print the results
print("Comparison of Top 6 Teams in Simulations:")
print(f"The first 6 teams from the real data were all in the top 6 positions {top_6_correct_position_percentage}% of the time across the simulations.")