# Subway Stations

Program to collect all information about the MTA subways and organize them for viewing per the user's request.

## Usage:
After compiling you must run the program in this format:

`./project subway_entrances.csv [THE-COMMAND-LIST-FILE]`

The `subway_entrances.csv` file has already been provided. This file comes from the official MTA website. You can download and view the visualization of the MTA subways here: https://data.cityofnewyork.us/Transportation/Subway-Entrances/drex-xx56/data

All user commands must be stored into a command file. There are 6 commands:
- **list_line_stations** *your_requested_line* <br>
  Description: View the stations in your request line.
- **list_all_stations** <br>
  Description: Lists all the subway stations in the MTA.
- **list_entrances** *your_requested_station_name* <br>
  Description: Lists all the entrances in a specified station. This excludes entrances that are actually only exits.
- **nearest_station** *longitude latitude* <br>
  Description: Outputs the closest station. This must be in longitude and latitude form.
- **nearest_lines** *longitude latitude* <br>
  Description: Outputs lines closest to the coordinates. There can be more than one line. This must be in longitude and latitude form.
- **nearest_entrance** *longitude latitude* <br>
  Description: Outputs the closest entrance. This excludes exists. This must be in longitude and latitude form.
  
I have already provided a command file `commands.txt` which includes a few commands.


## Compiling:
**OS COMPILED IN:**
- macOS Sierra 10.12
- Ubuntu 16.04

**COMPILING:** <br>
Using a makefile. Type: <br>
	> make

