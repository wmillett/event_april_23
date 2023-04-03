#!/usr/bin/env python3

import urllib.request
import json
import sys
import time
import shelve

# API endpoint
url = 'https://pokeapi.co/api/v2/pokemon/'

# Open cache
cache = shelve.open('cache')

# Get input from user
pokemon_name = input('Enter the name of a Pokemon: ')

# Check cache
if pokemon_name in cache:
    pokemon_data = cache[pokemon_name]
    print('Retrieving data from cache...')
else:
    # Make request to PokeAPI
    try:
        with urllib.request.urlopen(url + pokemon_name) as response:
            pokemon_data = json.loads(response.read().decode())
    except urllib.error.HTTPError as e:
        print('Error:', e.code)
        sys.exit(1)

    # Store in cache
    cache[pokemon_name] = pokemon_data

    # Wait for 1 second to avoid hitting the rate limit
    time.sleep(1)

# Extract name and abilities
name = pokemon_data['name'].capitalize()
abilities = [ability['ability']['name'].capitalize() for ability in pokemon_data['abilities']]

# Display results
print('Name:', name)
print('Abilities:')
for ability in abilities:
    print('-', ability)

# Close cache
cache.close()
