import matplotlib.pyplot as plt

# Sample data: replace these with your actual measurements
distance_values = [0, 20, 40, 60, 80, 100, 120, 140, 160, 180 , 200]  # in meters
ber_values =      [212, 256, 0.1/100, 0.2/100, 0.5/100, 0.8/100, 1/100, 1.2/100, 1.4/100, 1.7/100 , 2/100]  # BER values

# Plotting the data
plt.figure(figsize=(11, 11))
plt.plot(distance_values, ber_values, marker='o', linestyle='-', color='b')

# Adding titles and labels
plt.title('BER vs Distance (at rate 2.56 kbit/s)-(min power)')
plt.xlabel('Distance (meters)')
plt.ylabel('Average Bit Error Rate (BER) ')
plt.yscale('log')
plt.grid(True)
plt.ylim(1e-4, 1e0)
plt.xlim(0, 220)
# Display the plot
plt.show()