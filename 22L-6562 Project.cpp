#include<iostream>
#include<fstream>
using namespace std;

class Helper;
class Output;
class Date;
class Activity;
class Object;
class Comment;
class Post;
class Memory;
class Page;
class User;
class Facebook;

class Helper                                  // a class with helping functions to main tasks                
{
public:

	static int StringLength(const char* str)                    // to calculate string length
	{
		int c = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			c++;
		}
		return c;
	}

	static char* GetStringFromBuffer(const char* str)           // to get a string from temporary buffer
	{
		int l = Helper::StringLength(str);
		char* ptr = new char[l + 1];
		StringCopy(ptr, str);
		return ptr;
	}

	static void StringCopy(char*& dest, const char* src)      // to copy two strings
	{
		int length = StringLength(src);
		if (dest)
		{
			delete[] dest;
		}
		dest = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			dest[i] = src[i];
		}
		dest[length] = '\0';
	}

	static bool ExactMatch(char* myStr, const char* substr)     // to check if two array matches or not
	{
		bool flag = true; int r = 0;
		int size = Helper::StringLength(myStr);
		int size1 = Helper::StringLength(substr);
		for (int i = 0; i < size; i++)
		{
			if (myStr[i] == substr[0])
			{
				flag = true;
				int k = 1;
				for (int j = i + 1; j < i + size1; j++)
				{
					if (myStr[j] != substr[k])
					{
						flag = false;
						break;
					}
					k++;
				}
				if (flag == true)
				{
					break;
				}
			}
			else
			{
				flag = false;
			}
		}
		return flag;
	}

	static int CompareString(char* string1, const char* string2)           // to compare two strings
	{
		int result = 0;
		for (int i = 0; string1[i] != '\0' && string2[i] != '\0'; i++)
		{
			if (string1[i] == string2[i])
			{
				result = 0;
			}
			else if (string1[i] > string2[i])
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		if (result == 0)
		{
			int length1 = StringLength(string1);
			int length2 = StringLength(string2);
			if (length2 > length1)
			{
				return -1;
			}
			else if (length1 > length2)
			{
				return 1;
			}
			else
			{
				result = 0;
			}
		}
		return result;
	}

	static char* Conversion(int number)                 // to convert integer into char array
	{
		if (number >= 0)            // check if number is greater than zero 
		{
			int count = 0;
			int a = number;
			int b = 0;
			while (a > 0)
			{
				b = a % 10;
				count++;
				a = a / 10;
			}
			const int size = count;
			char* temp = new char[size + 1];
			temp[size] = '\0';
			int n = size - 1;
			while (number > 0)
			{
				int a = number % 10;
				temp[n--] = a + 48;
				number = number / 10;
			}
			return temp;
		}
		else            // if number is negative then returing a null pointer 
		{
			return NULL;
		}
	}

	static void StringConcatenate(char*& string1, char*& string2)    // to concatentate two strings
	{
		int size1 = StringLength(string1);
		int size2 = StringLength(string2);
		int newsize = size1 + size2;
		char* tempstring = new char[newsize + 1];
		for (int i = 0; i < size1; i++)
		{
			tempstring[i] = string1[i];
		}
		int k = 0;
		for (int i = size1; i < newsize; i++)
		{
			tempstring[i] = string2[k++];
		}
		tempstring[newsize] = '\0';
		delete string1;                  // deleting previous to avoid memory leakage
		string1 = tempstring;
	}

	static char* GenerateNewId(const char* c, int number)     // to generate a newid on basis of total static count of new posts and comments
	{
		char* temp = GetStringFromBuffer(c);
		char* c2 = Helper::Conversion(number);
		if (c2)                                             // check if c2 is not a null pointer
		{
			Helper::StringConcatenate(temp, c2);
			delete[]c2;
			c2 = 0;
			return temp;
		}
		else
		{
			delete[] temp;                                // if c2 is null then deleting temp to avoid memory leakage
			return nullptr;
		}
	}
};

class Output                                   // a class for appropriate and professional display formatting  
{
public:

	static void DisplaySetUser(const char* temp)      // to display the user which is to be set
	{
		cout << endl << "Command:\tSet current user '" << temp << "'" << endl;
	}

	static void DisplayCommand(const char* temp)  // to display Command
	{
		cout << endl << "Command:\t" << temp << endl;
	}

	static void Display1()           // to display a line 
	{
		cout << endl << "--------------------------------------------------------------------------------------------------------------------" << endl;
	}

	static void Display2(const char* temp)   // to dispaly statements 
	{
		cout << " " << temp << " " << endl << endl;
	}

	static void Display3()    // to display ending line
	{
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
};

class Date                            // a class for date of our posts and comments
{
private:

	int day;
	int month;
	int year;

public:

	static Date currentdate;                           // public static object of currentdate

	Date()                                             // default constructor of date class
	{
		day = 0;
		month = 0;
		year = 0;
	}

	static void	SetCurrentDate(int d, int m, int y)     // to set current date in our controller function
	{
		currentdate.day = d;
		currentdate.month = m;
		currentdate.year = y;
	}

	Date& operator--()                                // Overloaded operator of -- in order to get pervious date
	{
		Date newdate;
		newdate.day = day - 1;
		newdate.month = month;
		newdate.year = year;
		return newdate;
	}

	bool operator == (const Date& rhs)                 // Overloaded operator of == in order to make two date equal to each other
	{
		return(day == rhs.day && month == rhs.month && year == rhs.year);
	}

	bool operator < (const Date& rhs)                  // Overloaded operator of < in order to compare two years
	{
		return(year < rhs.year);
	}

	void ReadDateFromFile(ifstream& file)              // to read date from our file
	{
		file >> day;
		file >> month;
		file >> year;
	}

	static bool CheckLatestDate(Date orginal)                                       // to check if the date is latest ie either today or yesterday
	{
		return (orginal == Date::currentdate || orginal == --Date::currentdate);
	}

	static void PrintDateDifference(Date t1, Date t2)         // to display the date difference 
	{
		cout << " " << t2.year - t1.year << " Years Ago" << endl;
	}

	void Print()        // to print date
	{
		cout << " (" << day << "/" << month << "/" << year << ")" << endl;
	}

	~Date()       // destructor of date class
	{
		// cout << "Destructor called" << endl;
	}
};
Date Date::currentdate;          // to initialize static object of currentdate

class Activity       // a class for activity of Post
{
private:

	int type;
	char* value;

public:

	Activity()           // default cinstructor of Activity
	{
		type = 0;
		value = 0;
	}

	void ReadActivityFromFile(ifstream& file)       // to read activity from file
	{
		file >> type;
		char temp[50];
		file.getline(temp, 50);
		value = Helper::GetStringFromBuffer(temp);
	}

	void PrintActivity()          // to print activity
	{
		switch (type)
		{
		case 1:
			cout << " is Feeling" << value << endl;
			break;
		case 2:
			cout << " is Thinking about " << value << endl;
			break;
		case 3:
			cout << " is Making" << value << endl;
			break;
		case 4:
			cout << " is Celebrating" << value << endl;
			break;
		}
	}

	~Activity()                   // destructor of Activity
	{
		if (value)
			delete[] value;
	}
};

class Object       // A Parent class for User and Post having Common ID and some virtual functions
{
private:

	char* ID;

public:

	virtual void  AddPostToTimeline(Post* temp) = 0;     // pure virtual function of AddPostToTimeline

	virtual void  PrintName() = 0;       // pure virtual function to print name

	virtual bool checktimeline(Post* temp) = 0;
	Object()            // default constructor of Object 
	{
		ID = 0;
	}

	char* GetID()      // Getter if ID
	{
		return ID;
	}

	void SetID(char* temp)        // Setter if ID
	{
		ID = temp;
	}

	void PrintID()      // to print ID
	{
		cout << ID;
	}

	virtual ~Object()     // destructor of Object
	{
		if (ID)
			delete[] ID;
	}
};

class Comment      // a class of commments
{
private:

	char* ID;
	char* Text;
	Object* CommentBy;

public:

	static int commentcount;     // public static variable of total comments

	Comment()   // default constructor of Comment
	{
		ID = 0;
		Text = 0;
		CommentBy = 0;
	}
	Comment(Object* commentby, const char* text)   //Overloaded Constructor of Commment 
	{
		commentcount = commentcount + 1;
		ID = Helper::GenerateNewId("c", commentcount);
		CommentBy = commentby;
		Helper::StringCopy(Text, text);
	}

	void SetValues(const char* id, Object*& commentby, const char* txt)     // Settter to values of comment 
	{
		Helper::StringCopy(ID, id);
		CommentBy = commentby;
		Helper::StringCopy(Text, txt);
	}

	void PrintComment()  // to print comment
	{
		cout << "\t";
		CommentBy->PrintName();
		cout << " wrote:   " << Text << endl;
	}

	~Comment()        // destructor of comment
	{
		if (ID)
			delete[]  ID;
		if (Text)
			delete[]  Text;
	}
};
int Comment::commentcount = 0;  // initialization of static variable

class Post    // a class of Post 
{
private:

	int posttype;
	char* ID;
	Date SharedDate;
	char* text;
	Activity* activityptr;
	Object* SharedBy;
	Object** LikedBy;
	Comment** comments;
	int likedbycount;
	int commentcount;

public:

	static int postcount;      // a public static variable for total posts

	Post()     // default constructor of Post
	{
		posttype = 0;
		ID = 0;
		text = 0;
		activityptr = 0;
		SharedBy = 0;
		LikedBy = 0;
		comments = 0;
		likedbycount = 0;
		commentcount = 0;
	}

	Post(const char* temp, Object* s)    // Overloaded Constructor of Post
	{
		postcount = postcount + 1;
		SharedBy = s;
		SharedDate = Date::currentdate;
		text = Helper::GetStringFromBuffer(temp);
		ID = Helper::GenerateNewId("p", postcount);
		posttype = 0;
		activityptr = 0;
		LikedBy = 0;
		comments = 0;
		likedbycount = 0;
		commentcount = 0;
	}

	void ReadPostsFromFile(ifstream& file)   // to read post from file
	{
		file >> posttype;
		char temp[100];
		file >> temp;
		ID = Helper::GetStringFromBuffer(temp);
		SharedDate.ReadDateFromFile(file);
		file.ignore();
		file.getline(temp, 100);
		text = Helper::GetStringFromBuffer(temp);
		if (posttype == 2)
		{
			activityptr = new Activity;
			activityptr->ReadActivityFromFile(file);
		}
	}

	Object* GetSharedBy()    // Getter of Shared By
	{
		return SharedBy;
	}

	Date GetSharedDate()    // Getter of Shared Date
	{
		return SharedDate;
	}

	char* Gettext()    // Getter of text
	{
		return text;
	}

	char* GetID()    // Getter of ID
	{
		return ID;
	}

	void SetID(char* temp)        // Setter of ID
	{
		ID = temp;
	}

	void SetSharedBy(Object*& temp)          // Setter of Shared By
	{
		SharedBy = temp;
	}

	void SetLikedBy(Object*& temp)         // Setter of Liked By
	{
		if (LikedBy == nullptr && temp != 0)
		{
			LikedBy = new Object * [10];
		}
		if (temp && likedbycount < 10)
		{
			LikedBy[likedbycount++] = temp;
		}
		if (likedbycount > 10)
		{
			cout << "No Space available" << endl;
		}
	}

	void AddToLikedList(Object* temp = 0)   // to add to liked list
	{
		if (likedbycount < 10)
		{
			LikedBy[likedbycount++] = temp;
		}
	}

	void AddComment(Comment*& temp)    // to add comment
	{
		if (comments == nullptr && temp != 0)
		{
			comments = new Comment * [10];
		}
		if (temp && commentcount < 10)
		{
			comments[commentcount++] = temp;
		}
		if (commentcount > 10)
		{
			cout << "No Space available" << endl;
		}
	}

	void PostComment(Object* temp, const char* txt)    // to add a new comment
	{
		Comment* newComments = new Comment(temp, txt);
		AddComment(newComments);
	}

	void ViewPost()    // to print post
	{
		cout << endl;
		PrintPost();
		cout << endl;
	}

	void ViewLikedList()     // to print post which are liked
	{
		cout << "Post Liked By :" << endl << endl;
		PrintLikedBy();
		cout << endl;
	}

	void PrintLikedBy()    // to print liked by
	{
		for (int i = 0; i < likedbycount; i++)
		{
			LikedBy[i]->PrintID(); cout << "\t"; LikedBy[i]->PrintName(); cout << endl;
		}
	}

	virtual void PrintPost(bool currentdate = true, bool commentcheck = true)  // virtual function to Print Post
	{
		cout << "--- ";
		SharedBy->PrintName();
		if (posttype == 2)
		{
			if (activityptr)
				activityptr->PrintActivity();
		}
		else
		{
			cout << " shared ";
		}
		cout << "'" << text << "'";
		if (currentdate)
		{
			SharedDate.Print();
		}
		else
		{
			cout << endl;
		}
		if (commentcheck)
		{
			for (int i = 0; i < commentcount; i++)
			{
				comments[i]->PrintComment();
			}
		}
	}

	virtual~Post()    // a virtual destructor of Post
	{
		if (ID)
			delete[] ID;
		if (text)
			delete[] text;
		if (activityptr)
			delete activityptr;
		if (LikedBy)
			delete[] LikedBy;
		if (comments)
			for (int i = 0; i < commentcount; i++)
			{
				if (comments[i])
					delete comments[i];
			}
		delete[] comments;
	}
};
int Post::postcount = 0; // to initialize static variable of total posts

class Memory : public Post  // a child class of Post
{
private:

	Post* originalPost;

public:

	Memory(Post* orginal, const char* t, Object* sharedby) : Post(t, sharedby)   // Overloaded Constructor of Memory
	{
		originalPost = orginal;
	}

	void PrintPost(bool currentdate = true, bool commentcheck = true)       // to print memory 
	{
		cout << "--- ";
		GetSharedBy()->PrintName();
		cout << " shared a memory ---";
		Post::GetSharedDate().Print();
		cout << "'" << Post::Gettext() << "'" << endl;
		cout << "\t"; Date::PrintDateDifference(originalPost->GetSharedDate(), GetSharedDate());
		originalPost->PrintPost(true, false);
	}

	~Memory()    // destructor of Memory
	{
		// cout<< " Destructor called for Memory() <<endl; "
	}
};

class Page : public Object    // a class of Page which is alsp inherited to Object
{
private:

	char* title;
	int postcount;
	Post** timeline;

public:

	Page() :Object()    // Default Constructor of Page
	{
		title = 0;
		timeline = 0;
		postcount = 0;
	}

	void ReadPagesFromFile(ifstream& file)  // to read Pages from file
	{
		char temp[50];
		file >> temp;
		SetID(Helper::GetStringFromBuffer(temp));
		file.getline(temp, 50);
		title = Helper::GetStringFromBuffer(temp);
	}

	void AddPostToTimeline(Post* temp)  // to add post to its timeline
	{
		if (timeline == 0 && temp != 0)
		{
			timeline = new Post * [10];
		}
		if (temp && postcount < 10)
		{
			timeline[postcount++] = temp;
		}
		else
		{
			cout << "No space available" << endl;
		}
	}
	bool checktimeline(Post* temp)
	{
		bool flag = false;
		for (int i = 0; i < postcount; i++)
		{
			if (timeline[i] = temp)
			{
				flag = true;
				break;
			}

		}
		return flag;
	}
	void PrintLatestPost()      // to print latest post
	{
		if (postcount == 0)
		{
			cout << "No Post" << endl;
		}

		for (int i = 0; i < postcount; i++)
		{
			if (Date::CheckLatestDate(timeline[i]->GetSharedDate()))
			{
				cout << endl;
				timeline[i]->PrintPost(false);
				cout << endl;
			}
		}
	}

	void PrintTimeLine()    // to print timeline
	{
		if (postcount == 0)
		{
			cout << "No Post" << endl;
		}
		for (int i = 0; i < postcount; i++)
		{
			cout << endl;
			timeline[i]->PrintPost();
			cout << endl;
		}
	}

	void PrintName()     // to print name
	{
		cout << title;
	}

	void PrintListVeiw()   // to print its list view 
	{
		PrintID(); cout << "     " << title << endl;
	}

	void ViewPage()   // to print a page 
	{
		PrintName();
		cout << endl;
		PrintTimeLine();
	}

	~Page()    // destructor of Page
	{
		if (title)
			delete[] title;
		if (timeline)
			for (int i = 0; i < postcount; i++)
			{
				if (timeline[i])
					delete[] timeline[i];
			}
		delete[] timeline;
	}
};

class User : public Object     // a class of User which is alsp inherited to Object
{
private:

	char* fname;
	char* lname;
	int likedpagescount;
	int friendscount;
	int postcount;
	Post** timeline;
	Page** likedPages;
	User** friendlist;

public:

	User() : Object()    // default constructor of User 
	{
		fname = 0;
		lname = 0;
		likedPages = 0;
		friendlist = 0;
		likedpagescount = 0;
		friendscount = 0;
		postcount = 0;
		timeline = 0;
	}

	void ReadUsersFromFile(ifstream& file)   // to read Users from file
	{
		char temp[50];
		file >> temp;
		SetID(Helper::GetStringFromBuffer(temp));
		file >> temp;
		fname = Helper::GetStringFromBuffer(temp);
		file >> temp;
		lname = Helper::GetStringFromBuffer(temp);
	}

	void LikePage(Page*& temp)  // to add liked pages list
	{
		if (likedPages == 0 && temp != 0)
		{
			likedPages = new Page * [10];
		}
		if (temp && likedpagescount < 10)
		{
			likedPages[likedpagescount++] = temp;
		}
		else
		{
			cout << "No space available" << endl;
		}
	}

	void AddFriend(User*& temp)   // to add to friendlist
	{
		if (friendlist == 0 && temp != 0)
		{
			friendlist = new User * [10];
		}
		if (temp && friendscount < 10)
		{
			friendlist[friendscount++] = temp;
		}
		else
		{
			cout << "No space available" << endl;
		}
	}

	void SeeYourMemories()    // to see our memories
	{
		cout << endl << " We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago." << endl << endl;
		cout << " On this Day" << endl;
		if (postcount == 0)
		{
			cout << endl << "No Post available" << endl;
		}
		for (int i = 0; i < postcount; i++)
		{
			if (timeline[i]->GetSharedDate() < Date::currentdate)
			{
				Date::PrintDateDifference(timeline[i]->GetSharedDate(), Date::currentdate);
				timeline[i]->PrintPost();
			}
		}
	}

	void ViewFriendList()   // to view frient list of user
	{
		if (friendlist)
		{
			cout << endl;
			for (int i = 0; i < friendscount; i++)
			{
				friendlist[i]->PrintListVeiw();
			}
			cout << endl;
		}
		else
		{
			cout << endl << "No Friends" << endl << endl;
		}
	}

	void ViewHome()   // to view home page of user having post of friends and likedpages based on latest post 
	{
		if (friendscount == 0 && likedpagescount == 0)
		{
			cout << "No Friends and No Pages therefore NO POSTs in his Home Page" << endl;
		}
		for (int i = 0; i < friendscount; i++)
		{
			friendlist[i]->PrintLatestPost();
		}
		for (int i = 0; i < likedpagescount; i++)
		{
			likedPages[i]->PrintLatestPost();
		}
	}

	void ViewLikedPages()  //to view liked pages of user
	{
		if (likedPages)
		{
			cout << endl;
			for (int i = 0; i < likedpagescount; i++)
			{
				likedPages[i]->PrintListVeiw();
			}
			cout << endl;
		}
		else
		{
			cout << endl << "No liked Pages" << endl << endl;
		}
	}

	void AddPostToTimeline(Post* temp)   // to add post to timeline
	{
		if (timeline == 0 && temp != 0)
		{
			timeline = new Post * [10];
		}
		if (temp && postcount < 10)
		{
			timeline[postcount++] = temp;
		}
		else
		{
			cout << "No space available" << endl;
		}
	}
	bool checktimeline(Post* temp)
	{
		bool flag = false;
		for (int i = 0; i < postcount; i++)
		{
			if (timeline[i] == temp)
			{
				flag = true;
				break;
			}

		}
		return flag;
	}
	void PrintName()   // to print name
	{
		cout << fname << " " << lname;
	}

	void PrintLatestPost()   // to print latest post ie either of today or yesterday
	{
		for (int i = 0; i < postcount; i++)
		{
			if (Date::CheckLatestDate(timeline[i]->GetSharedDate()))
			{
				cout << endl;
				timeline[i]->PrintPost(false);
				cout << endl;
			}
		}
	}

	void PrintTimeLine()   // to print timeline of user 
	{
		if (postcount == 0)
		{
			cout << "No Post" << endl;
		}
		for (int i = 0; i < postcount; i++)
		{
			cout << endl;
			timeline[i]->PrintPost();
			cout << endl;
		}
	}

	void PrintListVeiw()    //to print its list view
	{
		PrintID(); cout << "\t" << fname << " " << lname << endl;
	}

	~User()   // destructor of User
	{
		if (fname)
			delete[] fname;
		if (lname)
			delete[] lname;
		if (likedPages)
			delete[] likedPages;
		if (friendlist)
			delete[] friendlist;
		if (timeline)
			for (int i = 0; i < postcount; i++)
			{
				if (timeline[i])
					delete[] timeline[i];
			}
		delete[] timeline;
	}
};

class Facebook   // Main Controller class
{
private:

	Page** Pages;
	User** Users;
	Post** Posts;
	int totalpages;
	int totalusers;

public:

	Facebook()   // default constructor of Facebook 
	{
		Pages = 0;
		Users = 0;
		Posts = 0;
		totalpages = 0;
		totalusers = 0;
	}

	void Load()  // to Load various files
	{
		LoadPagesFromFile("Pages.txt");
		LoadUsersFromFile("Users.txt");
		LoadPostsFromFile("Posts.txt");
		LoadCommentsFromFile("Comments.txt");
	}

	void LoadPagesFromFile(const char* fileName)    // to  Load Pages From File
	{
		ifstream file;
		file.open(fileName);
		if (file.is_open())
		{
			file >> totalpages;
			Pages = new Page * [totalpages];
			for (int i = 0; i < totalpages; i++)
			{
				Pages[i] = new Page;
				Pages[i]->ReadPagesFromFile(file);
			}
			file.close();
		}
	}

	void LoadUsersFromFile(const char* fileName)     // to  Load Users From File
	{
		ifstream file;
		file.open(fileName);
		if (file.is_open())
		{
			file >> totalusers;
			char*** tempfriend = new char** [totalusers];
			Page* pageptr = 0;
			User* userptr = 0;
			Users = new User * [totalusers];
			for (int i = 0; i < totalusers; i++)
			{
				char buffer[100];
				Users[i] = new User;
				Users[i]->ReadUsersFromFile(file);
				tempfriend[i] = new char* [10];
				int j = 0;
				while (1)
				{
					file >> buffer;
					if (Helper::CompareString(buffer, "-1") == 0)
					{
						tempfriend[i][j] = nullptr;
						break;
					}
					tempfriend[i][j] = Helper::GetStringFromBuffer(buffer);
					j++;
				}
				while (1)
				{
					file >> buffer;
					if (Helper::CompareString(buffer, "-1") == 0)
					{
						break;
					}
					pageptr = SearchPageByID(buffer);
					Users[i]->LikePage(pageptr);
				}
			}
			file.close();

			for (int i = 0; i < totalusers; i++)
			{
				for (int j = 0; tempfriend[i][j] != nullptr; j++)
				{
					userptr = SearchUserByID(tempfriend[i][j]);
					Users[i]->AddFriend(userptr);

					delete[]tempfriend[i][j];
				}
				delete[]tempfriend[i];
			}
			delete[]tempfriend;
			tempfriend = 0;

		}
	}

	void LoadPostsFromFile(const char* fileName)      // to  Load Posts From File
	{
		ifstream file;
		file.open(fileName);
		if (file.is_open())
		{
			file >> Post::postcount;
			Posts = new Post * [Post::postcount];
			for (int i = 0; i < Post::postcount; i++)
			{
				char temp[100];
				Posts[i] = new Post;
				Posts[i]->ReadPostsFromFile(file);
				file >> temp;

				Object* sharedBy = SearchObjectByID(temp);
				Posts[i]->SetSharedBy(sharedBy);
				sharedBy->AddPostToTimeline(Posts[i]);
				int j = 0;
				while (1)
				{
					file >> temp;
					if (Helper::CompareString(temp, "-1") != 0)
					{
						Object* likedBy = SearchObjectByID(temp);
						Posts[i]->SetLikedBy(likedBy);
					}
					else
					{
						break;
					}
				}
			}
			file.close();
		}
	}

	void LoadCommentsFromFile(const char* fileName)       // to  Load Comments From File
	{
		ifstream file;
		file.open(fileName);
		if (file.is_open())
		{
			file >> Comment::commentcount;

			for (int i = 0; i < Comment::commentcount; i++)
			{
				char temp[100];

				Comment* Comments = new Comment;
				file >> temp;
				char* ID = Helper::GetStringFromBuffer(temp);
				file >> temp;
				Post* postPtr = Facebook::SearchPostByID(temp);
				postPtr->AddComment(Comments);
				file >> temp;
				Object* commentby = SearchObjectByID(temp);
				file.getline(temp, 100);
				char* txt = Helper::GetStringFromBuffer(temp);
				Comments->SetValues(ID, commentby, txt);

				if (ID)
					delete[] ID;
				if (txt)
					delete[] txt;

			}
		}
	}

	void ShareMemory(const char* postid, Object* temp, const char* text)   // to share memory 
	{
		Post* posts = SearchPostByID(postid);
		if (posts && temp->checktimeline(posts))
		{
			Memory* m = new Memory(posts, text, temp);
			temp->AddPostToTimeline(m);
			ExpandPost(m);
		}
		else
		{
			cout << "Memory Cannot shared" << endl;
		}
	}

	void ExpandPost(Post* obj)    // to expand Post
	{
		Post** newpost = Posts;

		int newtotalposts = Post::postcount;
		Post::postcount = Post::postcount + 1;

		Posts = new Post * [Post::postcount];
		for (int i = 0; i < newtotalposts; i++)
		{
			*(Posts + i) = *(newpost + i);
		}

		*(Posts + newtotalposts) = obj;

		delete[] newpost;

	}
	Page* SearchPageByID(const char* temp)    // to Search Page By ID
	{
		Page* newlist = 0;
		for (int i = 0; i < totalusers; i++)
		{
			bool r = Helper::ExactMatch(Pages[i]->GetID(), temp);
			if (r)
			{
				newlist = Pages[i];
				break;
			}
		}
		return newlist;
	}

	Post* SearchPostByID(const char* temp)      // to Search Post By ID
	{
		Post* newlist = 0;
		for (int i = 0; i < Post::postcount; i++)
		{
			bool r = Helper::ExactMatch(Posts[i]->GetID(), temp);
			if (r)
			{
				newlist = Posts[i];
				break;
			}
		}
		return newlist;
	}

	User* SearchUserByID(char* temp)         // to Search User By ID
	{
		User* newlist = 0;
		for (int i = 0; i < totalusers; i++)
		{
			bool r = Helper::ExactMatch(Users[i]->GetID(), temp);
			if (r)
			{
				newlist = Users[i];
				break;
			}
		}
		return newlist;
	}

	Object* SearchObjectByID(char* temp)                 // to Search Object By ID
	{
		if (SearchUserByID(temp))
		{
			return SearchUserByID(temp);
		}
		else
		{
			return SearchPageByID(temp);
		}
	}

	void Execute()    // to execute the object of Facebook
	{
		char user1[] = "u1";
		Date::SetCurrentDate(15, 11, 2017);

		User* currentUser = SearchUserByID(user1);
		Output::DisplaySetUser(user1);
		Output::Display1();
		cout << endl;
		currentUser->PrintName();
		Output::Display2("successfully set as Current User");
		Output::Display3();

		Output::DisplayCommand("View Friend list");
		Output::Display1();
		currentUser->PrintName();
		Output::Display2("- Friend list");
		currentUser->ViewFriendList();
		Output::Display3();

		Output::DisplayCommand("View Liked Pages");
		Output::Display1();
		currentUser->PrintName();
		Output::Display2("- Liked Pages");
		currentUser->ViewLikedPages();
		Output::Display3();

		Output::DisplayCommand("View Home");
		Output::Display1();
		currentUser->PrintName();
		Output::Display2("- Home Page");
		currentUser->ViewHome();
		Output::Display3();

		Output::DisplayCommand("View Timeline");
		Output::Display1();
		currentUser->PrintName();
		Output::Display2("- Timeline");
		currentUser->PrintTimeLine();
		Output::Display3();

		Output::DisplayCommand("ViewLikedList (post5)");
		Output::Display1();
		Post* temp = SearchPostByID("post7");
		temp->ViewLikedList();
		Output::Display3();

		Output::DisplayCommand("LikedList (post5)");
		Output::DisplayCommand("ViewLikedList (post5)");
		Output::Display1();
		temp = SearchPostByID("post7");
		temp->AddToLikedList(currentUser);
		temp->ViewLikedList();
		Output::Display3();

		Output::DisplayCommand("PostComment(post8, Thanks for the wishes)");
		Output::DisplayCommand("ViewPost(post8)");
		Output::Display1();
		temp = SearchPostByID("post7");
		temp->PostComment(currentUser, "Thanks for the wishes");
		temp->ViewPost();
		Output::Display3();

		Output::DisplayCommand("SeeYourMemories()");
		Output::Display1();
		currentUser->SeeYourMemories();
		Output::Display3();

		Output::DisplayCommand("ShareMemory (post10,'Never thought I will be specialist in this field')");
		Output::DisplayCommand("View Timeline");
		Output::Display1();
		currentUser->PrintName();
		Output::Display2("- Timeline");
		ShareMemory("post10", currentUser, "Never thought I will be specialist in this field");
		currentUser->PrintTimeLine();
		Output::Display3();

		Output::DisplayCommand("ViewPage(p1)");
		Output::Display1();

		Page* search = SearchPageByID("p1");
		search->ViewPage();
		Output::Display3();

		char user2[] = "u11";
		currentUser = SearchUserByID(user2);
		Output::DisplaySetUser(user2);
		Output::Display1();
		cout << endl;
		currentUser->PrintName();
		Output::Display2("successfully set as Current User");
		Output::Display3();

		Output::DisplayCommand("View Home");
		Output::Display1();
		currentUser->PrintName();
		Output::Display2("- Home Page");
		Date::SetCurrentDate(15, 11, 2017);
		currentUser->ViewHome();
		Output::Display3();

		Output::DisplayCommand("View Timeline");
		Output::Display1();
		currentUser->PrintName();
		Output::Display2("- Timeline");
		currentUser->PrintTimeLine();
		Output::Display3();
	}

	~Facebook()                      // Destructor of Facebook() 
	{
		if (Pages)
			for (int i = 0; i < totalpages; i++)
			{
				if (Pages[i])
					delete Pages[i];
			}
		delete[] Pages;
		if (Users)
			for (int i = 0; i < totalusers; i++)
			{
				if (Users[i])
					delete Users[i];
			}
		delete[] Users;
		if (Posts)
			delete[] Posts;
	}
};

int main()                        // main function
{
	Facebook fb;
	fb.Load();
	fb.Execute();
	return 0;
}