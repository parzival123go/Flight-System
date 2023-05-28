#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Origin_Destination{
	string origin;
	string destination;
};

struct Cities {
	string city;
	string country; 
	string airport_code;
	int population;
};

struct Flight  {
	string aircraft;
	int capacity; 
	int frequency;
	int distance;
};

int readCities(Cities city[]){
ifstream fin;
fin.open("cities.txt");

int i=0;

fin>>city[i].city;
while(city[i].city != "END"){

fin>>city[i].airport_code;
fin>>city[i].country;
fin>>city[i].population;

i++;

fin>>city[i].city;
}
fin.close();

return i;	
}


int readFlights(Cities city[],Flight flights[][100],int num_Cities){
ifstream input;
input.open("flights.txt");
	
int num_flights=0,l1,l2,i;
string destination,origin;
	
	
			
		input>>origin;
		while (origin != "END" ){
		
		input>>destination;
			
		for(i=0;i<num_Cities;i++){
			if(origin==city[i].airport_code)
			l1=i;
		}
		for(i=0;i<num_Cities;i++){
			if(destination==city[i].airport_code)
			l2=i;
		}
			
		input>>flights[l1][l2].distance;
		input>>flights[l1][l2].aircraft;
		input>>flights[l1][l2].capacity;
		input>>flights[l1][l2].frequency;
		
		num_flights++;
		input>>origin;
}


input.close();

	return num_flights;
	
}

void query_city_name(Cities city[],int num_Cities){
string search;
int i,l;
bool found=false;

	cout<<"Please enter the name of a city: ";
	cin>>search;
	cout<<endl;
	
	for(i=0;i<=num_Cities;i++){
		if(search==city[i].city){
cout<<"Name of City"<<"\t"<<"Airport Code"<<"\t"<<"Country"<<"\t\t"<<"Population"<<endl;		
cout<<city[i].city<<"\t\t"<<city[i].airport_code<<"\t\t";
cout<<city[i].country<<"\t\t"<<city[i].population;
		found=true;		
		}
}

if(found==false)
cout<<"This city does not exist: "<<search;

cout<<endl;
cout<<"______________________________________________________________________";
cout<<endl<<endl;
}

void query_city_airport_code(Cities city[],int num_Cities){
string search;
int i;

	cout<<"Please enter the three-letter airport code of a city: ";
	cin>>search;
	cout<<endl;
	
	
if(search=="POS" || search=="MIA" || search=="YYZ"|| search=="JFK"|| search=="LAX"|| search=="BGI"){	
cout<<"Name of City"<<"\t"<<"Airport Code"<<"\t"<<"Country"<<"\t\t\t"<<"Population"<<endl<<endl;
	for(i=0;i<=num_Cities;i++){
		if(search==city[i].airport_code){
		cout<<city[i].city<<"\t"<<city[i].airport_code<<"\t\t";
		cout<<city[i].country<<"\t"<<city[i].population;		
		}
	}
	cout<<endl;
}

else
cout<<"A city with this airport code does not exist: "<<search<<endl;


cout<<"______________________________________________________________________";
cout<<endl<<endl;
}

bool findcode(string code){
	
	if(code=="POS" || code=="MIA"||code=="YYZ"||
	code=="JFK"||code=="LAX"||code=="BGI")
	return true;
	
	
	return false;
}

void flights_between_2_cities(Cities city[],int num_Cities,Flight flights[][100]){
	string origin,destination;
	int i,o,d;
	bool d_found=false,o_found=false;
	
cout<<"Please enter the three letter airport code of an origin city and a destination city"<<endl;
cout<<endl;
cout<<"Origin city:";
cin>>origin;
cout<<endl;
cout<<"Destination city:";
cin>>destination;
cout<<endl;

if(!findcode(origin))
cout<<"A city with this airpot code does not exist: "<<origin<<endl;

if(!findcode(destination))
cout<<"A city with this airpot code does not exist: "<<destination<<endl;	

if(origin=="POS"||origin=="MIA"||origin=="YYZ"||
origin=="JFK"||origin=="LAX"||origin=="BGI"||destination=="POS"||destination=="MIA"||
destination=="YYZ"||destination=="JFK"||destination=="LAX"||destination=="BGI"){

for(i=0;i<=num_Cities;i++){
	if(origin==city[i].airport_code){
	o=i;
	o_found=true;}
	if(destination==city[i].airport_code){
	d=i;
	d_found=true;}
}
}

if(d_found==true && o_found==true){
cout<<"Distance"<<"\t"<<"Aircraft"<<"\t"<<"Capacity"<<"\t"<<"Frequency"<<endl;

cout<<flights[o][d].distance<<"\t\t"<<flights[o][d].aircraft<<"\t\t";
cout<<flights[o][d].capacity<<"\t\t"<<flights[o][d].frequency<<endl<<endl;

}


cout<<"______________________________________________________________________";
cout<<endl<<endl;
}

void one_stop_flights(Cities city[],int num_flights,Flight flights[][100]){
	string origin,destination;
	int i,o,d,m,count;
	
cout<<"Please enter the three letter airport code of an origin city and a destination city"<<endl;
cout<<endl;
cout<<"Origin city:";
cin>>origin;
cout<<endl;
cout<<"Destination city:";
cin>>destination;
cout<<endl;	

if(!findcode(origin))
cout<<"A city with this airpot code does not exist: "<<origin<<endl;

if(!findcode(destination))
cout<<"A city with this airpot code does not exist: "<<destination<<endl;
	
if(origin=="POS"||origin=="MIA"||origin=="YYZ"||
origin=="JFK"||origin=="LAX"||origin=="BGI"||destination=="POS"||destination=="MIA"||
destination=="YYZ"||destination=="JFK"||destination=="LAX"||destination=="BGI"){

for(i=0;i<num_flights;i++){
	if(origin==city[i].airport_code)
	o=i;}
	
for(i=0;i<num_flights;i++){
	if(destination==city[i].airport_code)
	d=i;}
	
for(m=0;m<num_flights;m++){
if((flights[o][m].distance > 0) && (flights[m][d].distance > 0))
count++;
}

cout<<"The following are 1-stop flights from "<<origin<<" to "<<destination;
cout<<endl<<endl;

cout<<"There is/are "<<count<<" flight/s from "<<origin<<" to "<<destination;
cout<<endl;
}
	

cout<<"______________________________________________________________________";
cout<<endl<<endl;
}

void flights_from_a_city(Cities city[],int num_flights,Flight flights[][100]){
	Origin_Destination od;
	int i,d,count=0;
	bool partner=false;
	
cout<<"Please enter the three letter airport code of an origin city ."<<endl;
cout<<endl;
cout<<"Origin city:";
cin>>od.origin;
cout<<endl<<endl;

if(od.origin=="POS"||od.origin=="MIA"||od.origin=="YYZ"||od.origin=="JFK"||od.origin=="LAX"||od.origin=="BGI"){	


for(i=0;i<num_flights;i++){
	if(od.origin==city[i].airport_code){
	
cout<<"The following are flights from "<<city[i].city<<endl<<endl;
	
for(d=0;d<num_flights;d++){
	
if( flights[i][d].capacity>0 ){
	
if(flights[i][d].frequency==0)	
cout<<"There are daily flights between "<<city[i].city<<" and "<<city[d].city<<endl;
else
if(flights[i][d].frequency==1)	
cout<<"There are bi-weekly flights between "<<city[i].city<<" and "<<city[d].city<<endl;
else
if(flights[i][d].frequency==2)	
cout<<"There are weekly flights between "<<city[i].city<<" and "<<city[d].city<<endl;

cout<<"Aircraft: "<<flights[i][d].aircraft<<endl;
cout<<"Capacity: "<<flights[i][d].capacity<<endl;

if(flights[i][d].distance<0){
flights[i][d].distance=flights[i][d].distance* -1;
partner=true;}

cout<<"Distance: "<<flights[i][d].distance<<endl<<endl;
count++;

if(partner==true)
cout<<"NB: This flight is with a partner airline."<<endl<<endl;}

}


cout<<"There is/are flight/s from "<<city[i].city<<" to "<<count
<<" destination cities."<<endl;}

}

}
else 
cout<<"Invalid three-letter airport code"<<endl;

cout<<"______________________________________________________________________";
cout<<endl<<endl;
}

void flights_to_a_city(Cities city[],int num_flights,Flight flights[][100]){
	Origin_Destination od;
	bool partner=false;
	int i,d,count=0;
	
cout<<"Please enter the three letter airport code of a destination city ."<<endl;
cout<<endl;
cout<<"Destination city:";
cin>>od.destination;
cout<<endl;

if(od.destination=="POS"||od.destination=="MIA"||od.destination=="YYZ"||
od.destination=="JFK"||od.destination=="LAX"||od.destination=="BGI"){	

for(i=0;i<num_flights;i++){
	if(od.destination==city[i].airport_code){
		
cout<<"The following are flights to "<<city[i].city<<endl<<endl;
	
for(d=0;d<num_flights;d++){
	
if( flights[d][i].capacity>0 ){

if(flights[d][i].frequency==0)	
cout<<"There are daily flights between "<<city[d].city<<" and "<<city[i].city<<endl;
else
if(flights[d][i].frequency==1)	
cout<<"There are bi-weekly flights between "<<city[d].city<<" and "<<city[i].city<<endl;
else
if(flights[d][i].frequency==2)	
cout<<"There are weekly flights between "<<city[d].city<<" and "<<city[i].city<<endl;

cout<<"Aircraft: "<<flights[d][i].aircraft<<endl;
cout<<"Capacity: "<<flights[d][i].capacity<<endl;

if(flights[d][i].distance<0){
flights[d][i].distance=flights[d][i].distance* -1;
partner=true;}

cout<<"Distance: "<<flights[d][i].distance<<endl<<endl;
count++;

if(partner==true){
cout<<"NB: This flight is with a partner airline."<<endl<<endl;
partner=false;}}

}

cout<<"There is/are flight/s originating from "<<count
<<" cities going to "<<city[i].city<<endl;}

}

}
else 
cout<<"Invalid three-letter airport code"<<endl;

cout<<"______________________________________________________________________";
cout<<endl<<endl;

}
void display_statistics(Cities city[],int num_Cities,Flight flights[][100]){

	
string destination,origin;
int i,l1,l2,max=0,total_distance=0,o,d;


	for(o=0;o<num_Cities;o++){
		
	for(d=0;d<num_Cities;d++){
			
	if(flights[o][d].distance > max && (flights[o][d].distance>0)){
	max=flights[o][d].distance;
	l1=o;
	l2=d;}	
		
	if(flights[o][d].frequency==0 && flights[o][d].distance>0)
	total_distance=total_distance+(flights[o][d].distance*7);
		
	if(flights[o][d].frequency==1 && flights[o][d].distance>0)
	total_distance=total_distance+(flights[o][d].distance*2);
	
	if(flights[o][d].frequency==2 && flights[o][d].distance>0)
	total_distance=total_distance+(flights[o][d].distance*1);	
	}		
}
		
cout<<"Length of the longest direct flight: "<<max;
cout<<". It is between "<<city[l1].city<<" and "<<city[l2].city<<endl<<endl;
		
cout<<"Total miles flown by the airline per week: "<<total_distance<<endl;

cout<<"______________________________________________________________________";
cout<<endl<<endl;	
}


void printlist(){
cout<<"1. Query for City by Name"<<endl;
cout<<"2. Query for City by Airport Code "<<endl;
cout<<"3. Query for Flights between Two Cities "<<endl;
cout<<"4. Query for 1-Stop Flights between Two Cities"<<endl;
cout<<"5. Query for Flights from a City"<<endl;
cout<<"6. Query for Flights to a City "<<endl;
cout<<"7. Display Statistics"<<endl;
cout<<"8. Quit "<<endl<<endl;	
}
int main(){

Cities city[100];
Flight flights[100][100];
int num_Cities;
int num_flights;
int i,j,choice;

num_Cities=readCities(city);

num_flights=readFlights( city,flights, num_Cities);

printlist();

cout<<"Please select one of the following options by entering a digit: ";
cin>>choice;
cout<<endl;

while(choice!=8){

if((choice<1)||(choice>8)){
		cout<<"INVALID option entered!!!!"<<endl<<endl;
		printlist();	}

if (choice==1)
query_city_name( city, num_Cities);
if (choice==2)
query_city_airport_code( city, num_Cities);
if (choice==3)
flights_between_2_cities( city, num_Cities, flights);
if(choice==4)
one_stop_flights( city, num_flights, flights);
if(choice==5)
flights_from_a_city( city, num_Cities, flights);
if(choice==6)
flights_to_a_city( city, num_Cities, flights);
if(choice==7)
display_statistics(city, num_Cities, flights);

system("pause");
system("cls");

 printlist();

cout<<"Please select one of the following options by entering a digit: ";
cin>>choice;
cout<<endl;
}

cout<<"Thanks for using the Flight Information System (c) 2022. Goodbye!";

return 0;

}
