#if you use this, you will need to download, python3, requests, and bs4
import requests
from bs4 import BeautifulSoup
import csv

# Define the URL of the webpage
url = "https://www.ssa.gov/oact/babynames/decades/names1980s.html"

# Send a GET request to fetch the webpage content
response = requests.get(url)

# Check if the request was successful
if response.status_code == 200:
    # Parse the HTML content
    soup = BeautifulSoup(response.content, "html.parser")
    
    # Find the table containing the data
    table = soup.find("table", {"class": "t-stripe"})
    
    # Open a CSV file to write the data
    with open("baby_names_1980s.csv", "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        
        # Write the header row
        header = [th.text for th in table.find("tr").find_all("th")]
        writer.writerow(header)
        
        # Write each row of data
        for row in table.find_all("tr")[1:]:
            data = [td.text for td in row.find_all("td")]
            writer.writerow(data)
    
    print("Data copied to baby_names_1980s.csv successfully.")
else:
    print("Failed to fetch webpage content.")
