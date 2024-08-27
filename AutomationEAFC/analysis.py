import json

def compare_real_to_simulations(data):
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
    print("\nComparison of Simulation Positions with Real Data:")
    for team, percentage in simulation_position_percentages.items():
        if percentage != 0:
            fairline = 1 / (percentage / 100)
        else:
            fairline = 0
        print(f"{team} was in position {real_positions[team]} {percentage}% of the time. -> Fairline: {fairline:.2f}")
def compare_top_6(data):
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
    print("\nComparison of Top 6 Teams in Simulations:")
    print(f"The first 6 teams from the real data were all in the top 6 positions {top_6_correct_position_percentage}% of the time across the simulations.")

def compare_bottom_3(data):
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
    print("\nComparison of Bottom 3 Teams in Simulations:")
    print(f"The last 3 teams from the real data were all in the last 3 positions {bottom_3_correct_position_percentage}% of the time across the simulations.")

def compare_top_3(data):
    # Extract real data (Table 0)
    real_data = data["Table 0"]

    # Get the first 3 teams from the real data
    top_3_teams = [row['Club'] for row in real_data if row['Position'] <= 3]

    # Initialize counters for group comparison
    top_3_correct_position_count = 0

    # Iterate over simulation tables (Tables 1 to 10)
    for i in range(1, 11):
        table_key = f"Table {i}"
        table = data[table_key]
        
        # Get the top 3 teams in the current simulation table
        sim_top_3_teams = [row['Club'] if 'Club' in row else row['Team'] for row in table if row['Position'] <= 3]
        
        # Check if all top 3 teams from the real data are in the top 3 in the simulation
        if all(team in sim_top_3_teams for team in top_3_teams):
            top_3_correct_position_count += 1

    # Calculate the percentage
    top_3_correct_position_percentage = (top_3_correct_position_count / 10) * 100

    # Print the results
    print("\nComparison of top 3 Teams in Simulations:")
    print(f"The top 3 teams from the real data were all in the top 3 positions {top_3_correct_position_percentage}% of the time across the simulations.")

def compare_Four_Six(data):
    # Extract real data (Table 0)
    real_data = data["Table 0"]

    four_six_teams = [row['Club'] for row in real_data if row['Position'] <= 6 and row['Position'] > 3]

    # Initialize counters for group comparison
    four_six_correct_position_count = 0

    # Iterate over simulation tables (Tables 1 to 10)
    for i in range(1, 11):
        table_key = f"Table {i}"
        table = data[table_key]
        
        # Get the top 3 teams in the current simulation table
        sim_four_six_teams = [row['Club'] if 'Club' in row else row['Team'] for row in table if row['Position'] <= 6 and row['Position'] > 3]
        
        # Check if all top 3 teams from the real data are in the top 3 in the simulation
        if all(team in sim_four_six_teams for team in four_six_teams):
            four_six_correct_position_count += 1

    # Calculate the percentage
    four_six_correct_position_percentage = (four_six_correct_position_count / 10) * 100

    # Print the results
    print("\nComparison of Teams 4-6 in Simulations:")
    print(f"The teams 4-6 from the real data were all in the 4-6 positions {four_six_correct_position_percentage}% of the time across the simulations.")

def compare_seven_nine(data):
    # Extract real data (Table 0)
    real_data = data["Table 0"]

    seven_nine_teams = [row['Club'] for row in real_data if row['Position'] <= 9 and row['Position'] > 6]

    # Initialize counters for group comparison
    seven_nine_correct_position_count = 0

    # Iterate over simulation tables (Tables 1 to 10)
    for i in range(1, 11):
        table_key = f"Table {i}"
        table = data[table_key]
        
        # Get the top 3 teams in the current simulation table
        sim_seven_nine_teams = [row['Club'] if 'Club' in row else row['Team'] for row in table if row['Position'] <= 9 and row['Position'] > 6]
        
        # Check if all top 3 teams from the real data are in the top 3 in the simulation
        if all(team in sim_seven_nine_teams for team in seven_nine_teams):
            seven_nine_correct_position_count += 1

    # Calculate the percentage
    seven_nine_correct_position_percentage = (seven_nine_correct_position_count / 10) * 100

    # Print the results
    print("\nComparison of Teams 7-9 in Simulations:")
    print(f"The teams 7-9 from the real data were all in the 7-9 positions {seven_nine_correct_position_percentage}% of the time across the simulations.")

def compare_upper_half(data):
    # Extract real data (Table 0)
    real_data = data["Table 0"]

    upper_half_teams = [row['Club'] for row in real_data if row['Position'] <= 9 and row['Position'] > 6]

    # Initialize counters for group comparison
    upper_half_correct_position_count = 0

    # Iterate over simulation tables (Tables 1 to 10)
    for i in range(1, 11):
        table_key = f"Table {i}"
        table = data[table_key]
        
        # Get the top 3 teams in the current simulation table
        sim_upper_half_teams = [row['Club'] if 'Club' in row else row['Team'] for row in table if row['Position'] <= 9 and row['Position'] > 6]
        
        # Check if all top 3 teams from the real data are in the top 3 in the simulation
        if all(team in sim_upper_half_teams for team in upper_half_teams):
            upper_half_correct_position_count += 1

    # Calculate the percentage
    upper_half_correct_position_percentage = (upper_half_correct_position_count / 10) * 100

    # Print the results
    print("\nComparison of Teams upper half in Simulations:")
    print(f"The teams upper half from the real data were all in the upper half positions {upper_half_correct_position_percentage}% of the time across the simulations.")

def compare_bottom_half(data):
    # Extract real data (Table 0)
    real_data = data["Table 0"]

    bottom_half_teams = [row['Club'] for row in real_data if row['Position'] <= 9 and row['Position'] > 6]

    # Initialize counters for group comparison
    bottom_half_correct_position_count = 0

    # Iterate over simulation tables (Tables 1 to 10)
    for i in range(1, 11):
        table_key = f"Table {i}"
        table = data[table_key]
        
        # Get the top 3 teams in the current simulation table
        sim_bottom_half_teams = [row['Club'] if 'Club' in row else row['Team'] for row in table if row['Position'] <= 9 and row['Position'] > 6]
        
        # Check if all top 3 teams from the real data are in the top 3 in the simulation
        if all(team in sim_bottom_half_teams for team in bottom_half_teams):
            bottom_half_correct_position_count += 1

    # Calculate the percentage
    bottom_half_correct_position_percentage = (bottom_half_correct_position_count / 10) * 100

    # Print the results
    print("\nComparison of Teams bottom half in Simulations:")
    print(f"The teams bottom half from the real data were all in the bottom half positions {bottom_half_correct_position_percentage}% of the time across the simulations.")

def compare_finish_top_6(data):
    # Extract real data (Table 0)
    real_data = data["Table 0"]

    # Initialize a dictionary to count top 6 appearances
    top_6_counts = {row['Club']: 0 for row in real_data}

    # Iterate over simulation tables (Tables 1 to 10)
    for i in range(1, 11):
        table_key = f"Table {i}"
        table = data[table_key]
        
        # Check each team's position in the simulation
        for row in table:
            team_name = row['Club'] if 'Club' in row else row['Team']
            if row['Position'] <= 6:
                top_6_counts[team_name] += 1

    # Calculate and print percentage and Fairline
    print("\nTo Finish in Top 6: ")
    for team, count in top_6_counts.items():
        percentage = (count / 10) * 100
        if percentage != 0:
            fairline = 1 / (percentage / 100)
        else:
            fairline = 0
        print(f"{team} was in the top 6 {percentage:.2f}% across the simulations. -> Fairline: {fairline:.2f}")

def compare_not_finish_top_4(data):
    # Extract real data (Table 0)
    real_data = data["Table 0"]

    # Initialize a dictionary to count top 6 appearances
    top_6_counts = {row['Club']: 0 for row in real_data}

    # Iterate over simulation tables (Tables 1 to 10)
    for i in range(1, 11):
        table_key = f"Table {i}"
        table = data[table_key]
        
        # Check each team's position in the simulation
        for row in table:
            team_name = row['Club'] if 'Club' in row else row['Team']
            if row['Position'] >= 5:
                top_6_counts[team_name] += 1

    # Calculate and print percentage and Fairline
    print("\nNOT to Finish in Top 4: ")
    for team, count in top_6_counts.items():
        percentage = (count / 10) * 100
        if percentage != 0:
            fairline = 1 / (percentage / 100)
        else:
            fairline = 0
        print(f"{team} was NOT in the top 4 {percentage:.2f}% across the simulations. -> Fairline: {fairline:.2f}")

def compare_to_win_outright(data):
    # Extract real data (Table 0)
    real_data = data["Table 0"]

    # Initialize a dictionary to count top 6 appearances
    top_6_counts = {row['Club']: 0 for row in real_data}

    # Iterate over simulation tables (Tables 1 to 10)
    for i in range(1, 11):
        table_key = f"Table {i}"
        table = data[table_key]
        
        # Check each team's position in the simulation
        for row in table:
            team_name = row['Club'] if 'Club' in row else row['Team']
            if row['Position'] <= 1:
                top_6_counts[team_name] += 1

    # Calculate and print percentage and Fairline
    print("\nTo win outright: ")
    for team, count in top_6_counts.items():
        percentage = (count / 10) * 100
        if percentage != 0:
            fairline = 1 / (percentage / 100)
        else:
            fairline = 0
        print(f"{team} WON {percentage:.2f}% across the simulations. -> Fairline: {fairline:.2f}")


def main():
    # Load the JSON data
    with open('data.json') as file:
        data = json.load(file)

    # Run all three comparisons
    print("\n================================================================================================================================================\n")
    compare_top_3(data)
    compare_Four_Six(data)
    compare_seven_nine(data)
    compare_bottom_3(data)
    compare_top_6(data)
    compare_upper_half(data)
    compare_bottom_half(data)
    compare_finish_top_6(data)
    compare_not_finish_top_4(data)
    compare_to_win_outright(data)
    compare_real_to_simulations(data)

if __name__ == "__main__":
    main()