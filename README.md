# truck_uav_remake
Docs:
Algorithm: 


CoordMatrix: Read the TSP problems, creates Cost Matrices for Truck and Drones


ListOfCustomers: Stores "vector <int>" list of customers, provides attributes and functions to calculate the cost, get tour_size,...
  
  
Solution: Stores Solution and Best Solution, each Solution contains:   ListOfCustomers VehicleTour;
                                                                       vector <ListOfCustomers> DroneTour; 
          and provides attributes and fuctions for calculating cost, comparison between 2 Solutions. 
  
  
ListLabel: Stores ListOfLabel for Split Procedure:  vector <vector <pair<double,double>>> ListOfLabel; and attributes and functions.

TSPalgorithm: Main Algorithm.
