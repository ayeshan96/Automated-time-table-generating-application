//Header files
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<array>

//Declare namespace
using namespace std;

//Declare global variables
vector<vector<string>>academicYear;
vector<vector<string>>academicYearCourses;
vector<vector<string>>course;
vector<vector<string>>hall;
vector<vector<string>>lecturer;

//Functions in the code
void readExcelFile();
void passObjectsToClass();
void generateTimetable();

//Class
class Year
{
	//Data of the class
private:
	string year;
	string noOfStudents;
	vector <string> courses;

public:
	//Default constructor
	Year() {}

	//Funtion to set data
	void setData(string yr, string st, vector<string> crs)
	{
		year = yr;
		noOfStudents = st;
		courses = crs;
	}

	//Function to show data
	void showData()
	{
		cout << year << "\t" << noOfStudents << "\t\t\t";
		/*for (int i = 0; i < 6; i++)
		{
			cout << courses[i] << "\t";
		}*/
		cout << endl;
	}
};

//Lecturer class
class Lecturer
{
//Data of the class
private:
	string lecturerId;
	string lecturerName;
	vector <string> courses;

	//Function of the class
public:

	//Default constructor
	Lecturer() {}

	//Function to set data
	void setData(string lecID, string lecName)
	{
		lecturerId = lecID;
		lecturerName = lecName;
	}

	//Funtion to show data
	void showData()
	{
		cout << lecturerId << "\t" << lecturerName;
		cout << endl;
	}
};

//Lecturehall class
class LectureHall
{
	//Define data
private:
	string hallID;
	string code;
	string noOfSeats;

	//Declare functions
public:

	//Default constructor
	LectureHall() {}

	//Function to setData
	void setData(string hID, string cd, string cap)
	{
		hallID = hID;
		code = cd;
		noOfSeats = cap;
	}

	//Function to showData
	void showData()
	{
		cout << hallID << "\t" << code << "\t" << noOfSeats;
		cout << endl;
	}
};


//Course class
class Course
{
	//Private data members
private:
	string courseID;
	string code;
	string courseName;
	string lecturerId;
	string enrolledStudents;
	string duration;

public:
	
	//Function to set data
	void setData(string crsID, string cd, string crname, string lecID, string enrStu, string dur)
	{
		//Assign values
		courseID = crsID;
		code = cd;
		courseName = crname;
		lecturerId = lecID;
		enrolledStudents = enrStu;
		duration = dur;
	}

	//Function to show data
	void showData()
	{
		cout << courseID << "\t" << code << "\t" << courseName << "\t\t" << lecturerId << "\t\t\t" << enrolledStudents << "\t\t" << duration;
		cout << endl;
	}
};

//Function to read .csv files
void readExcelFile()
{
	ifstream file1;

	//Open Academic year file and get the data
	file1.open("Acedemic Year.csv");

	if (file1.fail())
	{
		//Output to the console window
		cout << "There is an error in open the file\n\n\n\n";
	}

	else
	{
		//Declare variables
		string row;
		int noAccYr = 0;

		//Assigning values to the vector academicYear and academicYearCourses
		while (getline(file1, row))
		{
			stringstream ss(row);
			vector<string>tem1;
			vector<string>tem2;
			tem1.clear();
			tem2.clear();
			int i = 0;
			noAccYr++;
			while (ss.good())
			{

				string column = "";
				getline(ss, column, ',');

				if (column != "")
				{
					i++;
					tem1.push_back(column);
					if (i >= 3)
					{
						tem2.push_back(column);
					}
				}
			}
			academicYear.push_back(tem1);
			academicYearCourses.push_back(tem2);
		}
	}

	//Close the file
	file1.close();

	//Open the Course file
	ifstream file2;
	file2.open("Course.csv");

	//Check whether the file is open
	if (file2.fail())
	{
		//Output to the console window
		cout << "There is an error in open the file\n\n\n\n";
	}

	else
	{
		//Declare variables
		string row;

		//Assign values to the vector
		while (getline(file2, row))
		{
			stringstream ss(row);
			vector<string>tem1;
			tem1.clear();

			while (ss.good())
			{

				string column = "";
				getline(ss, column, ',');

				if (column != "")
				{
					tem1.push_back(column);
				}


			}
			course.push_back(tem1);

		}
	}
	//Close the file
	file2.close();

	//Opent the Hall.csv file
	ifstream file3;
	file3.open("Hall.csv");

	//Check whether the file is open
	if (file3.fail())
	{
		//Output to the console window
		cout << "There is an error in open the file\n\n\n\n";
	}

	else
	{
		//Declare variables
		string row;

		//Assign valuues to the vector
		while (getline(file3, row))
		{
			stringstream ss(row);
			vector<string>tem1;
			tem1.clear();

			while (ss.good())
			{

				string column = "";
				getline(ss, column, ',');

				if (column != "")
				{
					tem1.push_back(column);
				}

			}
			hall.push_back(tem1);

		}
	}
	//Close the file
	file3.close();


	//Open the Lecturer.csv file
	ifstream file4;
	file4.open("Lecturer.csv");

	//Check whether the file is open
	if (file4.fail())
	{
		//Output to the console window
		cout << "There is an error in open the file\n\n\n\n";
	}

	else
	{
		//Declare variables
		string row;

		//Assign values to the vector
		while (getline(file4, row))
		{
			stringstream ss(row);
			vector<string>tem1;
			tem1.clear();

			while (ss.good())
			{
				string column = "";
				getline(ss, column, ',');

				if (column != "")
				{
					tem1.push_back(column);
				}
			}
			lecturer.push_back(tem1);
		}
	}
	//Close the file
	file4.close();
}

//Function to create objects and send data to classes
void passObjectsToClass()
{
	//Declare DMA
	Year *acaYr = new Year[academicYear.size()];

	//Output to the console window
	cout << endl << endl << "\t\t___ACADEMIC YEAR DETAILS___" << endl << endl;
	cout << "Year\tNo. of Students"/*\t\tCourses" */<< endl << endl;

	//Create objects and pass to the classes
	for (int i = 0; i < academicYear.size() - 1; i++)
	{
		acaYr[i].setData(academicYear[i + 1][0], academicYear[i + 1][1], academicYearCourses[i + 1]);

		//Call the function
		acaYr[i].showData();
	}

	//Declare DMA
	LectureHall *lHall = new LectureHall[hall.size()];

	//Output to the console window
	cout << endl << endl << endl << "\t\t___LECTURE HALL DETAILS___" << endl << endl;
	cout << "ID\tCode\tCapacity" << endl << endl;

	//Create objects and pass to the classes
	for (int i = 0; i < hall.size() - 1; i++)
	{
		lHall[i].setData(hall[i + 1][0], hall[i + 1][1], hall[i + 1][2]);
		
		//Call the function
		lHall[i].showData();
	}

	//Declare DMA
	Course *crs = new Course[course.size()];

	//Output to the console window
	cout << endl << endl << endl << "\t\t___COURSE DETAILS___" << endl << endl;
	cout << "ID\tCode\tName\t\t\t\tLecture ID\t\tNo. Of Students\t\tDuration(Hours)" << endl << endl;

	//Create objects and pass to the classes
	for (int i = 0; i < course.size() - 1; i++)
	{
		crs[i].setData(course[i + 1][0], course[i + 1][1], course[i + 1][2], course[i + 1][3], course[i + 1][4], course[i + 1][5]);
		
		//Call the function
		crs[i].showData();
	}

	//Declare DMA
	Lecturer *lecd = new Lecturer[lecturer.size()];

	//Output to the console window
	cout << endl << endl << endl << "\t\t___LECTURER DETAILS___" << endl << endl;
	cout << "ID\tName" << endl << endl;

	//Create objects and pass to the classes
	for (int i = 0; i < lecturer.size() - 1; i++)
	{
		lecd[i].setData(lecturer[i + 1][0], lecturer[i + 1][1]);

		//Call the function
		lecd[i].showData();
	}
}


//Function to generate the timetable
void generateTimetable()
{
second:

	//Declare variables
	int sizeofacarow;

	//Assign values
	sizeofacarow = academicYear.size() - 1;

	//Declare 3D DMA to assign course 
	string ***arr = new string**[8];
	for (int i = 0; i < 8; i++)
	{
		arr[i] = new string*[5];

		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = new string[sizeofacarow];

		}
	}

	//Declare 3D DMA to assign lectures
	string ***lec = new string**[8];
	for (int i = 0; i < 8; i++)
	{
		lec[i] = new string*[5];

		for (int j = 0; j < 5; j++)
		{
			lec[i][j] = new string[sizeofacarow];

		}
	}

	//Assign DMA elements and assign courses
	for (int i = 1; i < academicYear.size(); i++)
	{

		for (int j = 2; j < academicYear[i].size(); j++)
		{

			string code = academicYear[i][j];
			int duration;

			for (int g = 1; g < course.size(); g++)
			{

				if (course[g][1] == code)
				{
					duration = stoi(course[g][5]);
				}

			}

		first1:
			srand(time(0));
			int random1 = (rand() % 8);
			int random2 = (rand() % 5);


			//Check whether the DMA element is empty
			if (arr[random1][random2][i - 1] == "")
			{

				for (int y = random1; y < random1 + duration; y++)
				{
					if (y < 8)
					{
						if (arr[y][random2][i - 1] != "")
						{
							goto first1;
						}

					}
					else
					{
						goto first1;
					}
				}

				for (int x = random1; x < random1 + duration; x++)
				{
					arr[x][random2][i - 1] = academicYear[i][j];

				}
			}
			else
			{
				goto first1;
			}
		}
	}


	//Check each assigned courses with the lecturer
	for (int z = 0; z < sizeofacarow; z++)
	{
		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				string tem = arr[x][y][z];
				for (int i = 1; i < lecturer.size(); i++)
				{
					for (int j = 2; j < lecturer[i].size(); j++)
					{
						if (lecturer[i][j] == tem)
						{
							lec[x][y][z] = lecturer[i][1];
						}
					}
				}
			}
		}
	}


	//Check whether there is same lecturer duties in different academic years
	for (int y = 0; y < 5; y++)
	{
		//Declare and assign values
		int final1 = 0;
		int final2 = 0;

	four:

		for (int x = 0; x < 8; x++)
		{

			string *temarray1 = new string[sizeofacarow];
			string *temarray2 = new string[sizeofacarow];
			for (int z = 0; z < sizeofacarow; z++)
			{
				if (lec[x][y][z] != "")
				{
					temarray1[z] = lec[x][y][z];
					temarray2[z] = lec[x][y][z];

				}
			}

			for (int i = 0; i < sizeofacarow; i++)
			{
				for (int j = 0; j < sizeofacarow; j++)
				{

					if (i != j)
					{
						if (temarray1[i] != "" || temarray2[j] != "")
						{
							if (temarray1[i] == temarray2[j])
							{

								string coursecode1 = arr[x][y][i];
								string coursecode2 = arr[x][y][j];
								string lecturename = lec[x][y][i];


								int duration;

								for (int g = 1; g < course.size(); g++)
								{

									if (course[g][1] == coursecode1)
									{

										duration = stoi(course[g][5]);
									}

								}

								int count = 0;


								for (int g = final1; g < 8; g++)
								{

									if (arr[g][y][i] == "" || arr[g][y][i] == coursecode1)
									{
										count = count + 1;
									}

									else
									{
										count = 0;
									}

									if (count == duration)
									{

										count = 0;
										for (int d = 0; d < 8; d++)
										{

											if (arr[d][y][i] == coursecode1)
											{

												arr[d][y][i] = "";
												lec[d][y][i] = "";
											}
										}

										for (int d = g; d > (g - duration); d--)
										{

											arr[d][y][i] = coursecode1;
											lec[d][y][i] = lecturename;
										}

										final1 = (g - duration + 2);
										goto four;

									}

									if (g == 7 && count != duration)
									{
										int count2 = 0;

										for (int g2 = final2; g2 < 8; g2++)
										{
											if (arr[g2][y][j] == "" || arr[g2][y][j] == coursecode2)
											{
												count2 = count2 + 1;
											}

											else
											{
												count2 = 0;
											}

											if (count2 == duration)
											{

												count2 = 0;
												for (int d = 0; d < 8; d++)
												{

													if (arr[d][y][j] == coursecode2)
													{

														arr[d][y][j] = "";
														lec[d][y][j] = "";
													}
												}

												for (int d = g2; d > g2 - duration; d--)
												{

													arr[d][y][j] = coursecode2;
													lec[d][y][j] = lecturename;
												}


												final2 = (g2 - duration + 2);
												goto four;

											}

											if (g2 == 7 && count2 != duration)
											{
												goto second;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}


	string ***ha = new string**[8];
	for (int i = 0; i < 8; i++)
	{
		ha[i] = new string*[5];

		for (int j = 0; j < 5; j++)
		{
			ha[i][j] = new string[sizeofacarow];

		}
	}

	//Clear the screen
	system("cls");
fourth:

	//Output to the console window
	cout << "ASSIGN LECTURE HALLS TO FOLLOWING COURSES\n\n\n";
	cout << "LECTURE HALL\tMaximum Capacity\n\n\n";

	for (int i = 1; i < hall.size(); i++)
	{
		//Output to the console window
		cout << i << "  -  " << hall[i][1] <<"\t\t"<<hall[i][2]<< endl;
	}
	cout << endl << endl;


	string **temhall = new string*[course.size() - 1];
	for (int i = 0; i < course.size() - 1; i++)
	{
		temhall[i] = new string[2];
	}


	//Assign lecture hall to each course
	for (int i = 1; i < course.size(); i++)
	{
	third:

		int a;

		//Output to the console window
		cout << endl << course[i][1] << " - " << course[i][2] <<"   (No. of Students - "<<course[i][4]<<")"<< endl;

		//Get user input
		cin >> a;

		//Validate the user input
		if (a > 0 && a < hall.size())
		{
			//Check whether the lecture hall capacity is enough
			if (stoi(hall[a][2]) < stoi(course[i][4]))
			{
				cout << "\n\nThat halls capacity is not enough reenter\n\n";
				goto third;
			}

			else
			{
				//Assign lecture halls
				temhall[i - 1][0] = course[i][1];
				temhall[i - 1][1] = hall[a][1];
			}
		}
		else
		{
			//Output to the console window
			cout << "\n\nINVALID INPUT...... PLEASE ENTER OTHER LECTURE HALL..." << endl << endl;
			goto third;
		}
	}

	//Assign values
	for (int z = 0; z < sizeofacarow; z++)
	{
		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				for (int i = 0; i < course.size() - 1; i++)
				{
					if (arr[x][y][z] == temhall[i][0])
					{
						ha[x][y][z] = temhall[i][1];
					}
				}
			}
		}
	}

	//Check whether the lecture halls are crashed
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			string *temarray1 = new string[sizeofacarow];
			string *temarray2 = new string[sizeofacarow];
			for (int z = 0; z < sizeofacarow; z++)
			{
				if (ha[x][y][z] != "")
				{
					temarray1[z] = ha[x][y][z];
					temarray2[z] = ha[x][y][z];

				}
			}

			for (int i = 0; i < sizeofacarow; i++)
			{
				for (int j = 0; j < sizeofacarow; j++)
				{
					if (i != j)
					{
						if (temarray1[i] != "" || temarray2[j] != "")
						{
							if (temarray1[i] == temarray2[j])
							{
								//Clear the screen
								system("cls");

								//Output to the console window
								cout << "\n\nLecture halls are crashed...... Please assign lecture halls again......\n\n\n\n" << endl;
								
								//Retake the user inputs
								goto fourth;
							}
						}
					}
				}
			}
		}
	}

	//Declare DMA to store timetable
	string ***finalarray = new string**[11];
	for (int i = 0; i < 11; i++)
	{
		finalarray[i] = new string*[6];

		for (int j = 0; j < 6; j++)
		{
			finalarray[i][j] = new string[sizeofacarow];

		}
	}


	//Assign values to final array
	for (int z = 0; z < sizeofacarow; z++)
	{
		for (int x = 2; x < 6; x++)
		{
			for (int y = 1; y < 6; y++)
			{
				finalarray[x][y][z] = arr[x - 2][y - 1][z] + "  " + lec[x - 2][y - 1][z] + "  " + ha[x - 2][y - 1][z];
			}

		}
		for (int x = 7; x < 11; x++)
		{
			for (int y = 1; y < 6; y++)
			{
				finalarray[x][y][z] = arr[x - 3][y - 1][z] + "  " + lec[x - 3][y - 1][z] + "  " + ha[x - 3][y - 1][z];
			}

		}

	}

	//Assign values to the 3D vector
	for (int z = 0; z < sizeofacarow; z++)
	{
		int q = z + 1;
		finalarray[0][3][z] = "*****..........YEAR " + academicYear[z + 1][0] + "  TIME TABLE..........*****";

		finalarray[1][0][z] = "    TIME";
		finalarray[1][1][z] = "  MONDAY";
		finalarray[1][2][z] = "  TUESDAY";
		finalarray[1][3][z] = "  WEDNESDAY";
		finalarray[1][4][z] = "  THURSDAY";
		finalarray[1][5][z] = "  FRIDAY";
		finalarray[2][0][z] = "08.00 - 09.00";
		finalarray[3][0][z] = "09.00 - 10.00";
		finalarray[4][0][z] = "10.00 - 11.00";
		finalarray[5][0][z] = "11.00 - 12.00";
		finalarray[6][3][z] = "  INTERVAL";
		finalarray[7][0][z] = "01.00 - 02.00";
		finalarray[8][0][z] = "02.00 - 03.00";
		finalarray[9][0][z] = "03.00 - 04.00";
		finalarray[10][0][z] = "04.00 - 05.00";
	}

	//Create a .csv file to give the output
	ofstream tables;

	//Gpen the file
	tables.open("timetable.csv");

	//Output to the .csv file
	for (int z = 0; z < sizeofacarow; z++)
	{
		for (int x = 0; x < 11; x++)
		{
			for (int y = 0; y < 6; y++)
			{
				tables << finalarray[x][y][z] << ",";
			}
			tables << "\n";
		}
		tables << "\n\n\n\n\n";
	}
	tables.close();

	//Clear the screen
	system("cls");
}

//Main function
int main()
{
	//Output to the console window
	cout << endl << endl << "\t\t\t\t***_________AUTOMATED TIMETABLE GENERATING APPLICATION_________***" << endl << endl << endl << endl;
	
	//Call the function
	readExcelFile();

udata:

	//Output to the console window
	cout << endl << "***___Select Any Option___***" << endl << endl << endl;
	cout << "\t\tTo View Details\t\t - \t1 " << endl;
	cout << "\t\tTo Generate Timetable\t -\t2 " << endl;
	cout << endl << "Enter your option here  - ";

	//Declare variables
	int userInput;

	//Get the user input
	cin >> userInput;

	//Check the user imput
	if (userInput == 1)
	{
		//Clear the screen
		system("cls");

		//Call the function
		passObjectsToClass();

		//Output to the console window
		cout << endl << endl << endl <<endl;

		//Wait for the user input
		system("pause");

		//Clear the screen
		system("cls");
		goto udata;
	}

	else if (userInput == 2)
	{
		//Clear the screen
		system("cls");
		cout << "\n\n\t\tLoading......";

		//Call the function
		generateTimetable();

		//Clear the screen
		system("cls");

		//Output to the console window
		cout << "\n\n\n\n\t\tSUCCESSFUL!!!!\n\n\n\n\tPlease Open The .csv File to view the Timetable......\n\n" << endl << endl;
	}

	else
	{
		//Clear the screen
		system("cls");

		//Output to the console window
		cout << "******Wrong Input.....Please Enter Your Option Again......." << endl << endl;
		system("cls");
		goto udata;
	}

	//Waiting for the uset input
	system("pause");
	return 0;
}

