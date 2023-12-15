#include "htsystem.h"

htSystem::htSystem() {}

/**********************************Total Memory***************************************************/
//Lets return the memory from /proc/meminfo in KB
int htSystem::memTKB(){
    FILE *meminf = fopen("/proc/meminfo", "r"); //Open for read /proc/meminfo
    if(meminf == NULL){
        //if the file doesn't exist lets error out and let the user know
        cout << "ERROR: Can't find '/proc/meminfo'" << endl;
        return -1;
    }

    char line[256]; //This will be to read the lines of the file
    while(fgets(line, sizeof(line), meminf))
    {
        int ram; //Holder for Ram amount
        if(sscanf(line, "MemTotal: %d kB", &ram) == 1) //Pull the Decimal value from the MemTotal Line
        {
            fclose(meminf); //Lets Close the File then return the ram
            return ram;
        }
    }

    return -1;
}

//Lets return the memory from /proc/meminfo in MB
double htSystem::memTMB(){
    const double megabyte = 1024; //use this to divide the KB total in the end to produce amount in MB
    FILE *meminf = fopen("/proc/meminfo", "r"); //Open for read /proc/meminfo
    if(meminf == NULL){
        //if the file doesn't exist lets error out and let the user know
        cout <<"ERROR: Can't find '/proc/meminfo'" << endl;
        return -1;
    }

    char line[256]; //This will be to read the lines of the file
    while(fgets(line, sizeof(line), meminf)){
        int ram; //Holder for Ram amount
        if(sscanf(line, "MemTotal: %d kB", &ram) == 1) //Pull the Decimal value from the MemTotal Line
        {
            fclose(meminf); //Lets Close the File then return the ram
            return ram / megabyte;
        }
    }

    return -1;
}

//Lets return the memory from /proc/meminfo in GB
double htSystem::memTGB(){
    const double gigabyte = 1024 * 1024; //use this to divide the KB total in the end to produce amount in GB
    FILE *meminf = fopen("/proc/meminfo", "r"); //Open for read /proc/meminfo
    if(meminf == NULL){
        //if the file doesn't exist lets error out and let the user know
        cout <<"ERROR: Can't find '/proc/meminfo'" << endl;
        return -1;
    }

    char line[256]; //This will be to read the lines of the file
    while(fgets(line, sizeof(line), meminf)){
        int ram; //Holder for Ram amount
        if(sscanf(line, "MemTotal: %d kB", &ram) == 1) //Pull the Decimal value from the MemTotal Line
        {
            fclose(meminf); //Lets Close the File then return the ram
            return ram / gigabyte;
        }
    }

    return -1;
}
/******************************End Total Memory***************************************************/

/***********************************Free Memory***************************************************/

//Lets return the Free memory from /proc/meminfo in KB
int htSystem::memFKB(){
    FILE *meminf = fopen("/proc/meminfo", "r"); //Open for read /proc/meminfo
    if(meminf == NULL){
        //if the file doesn't exist lets error out and let the user know
        cout <<"ERROR: Can't find '/proc/meminfo'" << endl;
        return -1;
    }

    char line[256]; //This will be to read the lines of the file
    while(fgets(line, sizeof(line), meminf)){
        int ram; //Holder for Ram amount
        if(sscanf(line, "MemFree: %d kB", &ram) == 1) //Pull the Decimal value from the MemFree Line
        {
            fclose(meminf); //Lets Close the File then return the  Free ram
            return ram;
        }
    }

    return -1;

}

//Lets return the Free memory from /proc/meminfo in MB
double htSystem::memFMB(){
    const double megabyte = 1024;
    FILE *meminf = fopen("/proc/meminfo", "r"); //Open for read /proc/meminfo
    if(meminf == NULL){
        //if the file doesn't exist lets error out and let the user know
        cout <<"ERROR: Can't find '/proc/meminfo'" << endl;
        return -1;
    }

    char line[256]; //This will be to read the lines of the file
    while(fgets(line, sizeof(line), meminf)){
        int ram; //Holder for Ram amount
        if(sscanf(line, "MemFree: %d kB", &ram) == 1) //Pull the Decimal value from the MemFree Line
        {
            fclose(meminf); //Lets Close the File then return the  Free ram
            return ram / megabyte;
        }
    }

    return -1;

}

//Lets return the Free memory from /proc/meminfo in GB
double htSystem::memFGB(){
    const double gigabyte = 1024 * 1024;
    FILE *meminf = fopen("/proc/meminfo", "r"); //Open for read /proc/meminfo
    if(meminf == NULL){
        //if the file doesn't exist lets error out and let the user know
        cout <<"ERROR: Can't find '/proc/meminfo'" << endl;
        return -1;
    }

    char line[256]; //This will be to read the lines of the file
    while(fgets(line, sizeof(line), meminf)){
        int ram; //Holder for Ram amount
        if(sscanf(line, "MemFree: %d kB", &ram) == 1) //Pull the Decimal value from the MemFree Line
        {
            fclose(meminf); //Lets Close the File then return the  Free ram
            return ram / gigabyte;
        }
    }

    return -1;

}

/*******************************End Free Memory***************************************************/

/***********************************Used Memory***************************************************/

//Lets return the Used memory from /proc/meminfo in KB
int htSystem::memUKB(){
    FILE *meminf = fopen("/proc/meminfo", "r"); //Open for read /proc/meminfo
    if(meminf == NULL){
        //if the file doesn't exist lets error out and let the user know
        cout <<"ERROR: Can't find '/proc/meminfo'" << endl;
        return -1;
    }

    char line[256]; //This will be to read the lines of the file
    while(fgets(line, sizeof(line), meminf)){
        int ram, fRam; //Holder for Ram amount
        if(sscanf(line, "MemTotal: %d kB", &ram) == 1){} //Pull the Decimal value from the MemFree Line
        if(sscanf(line, "MemFree: %d kB", &fRam) == 1) //Pull the Decimal Value from the MemFree
        {
            fclose(meminf); //Lets Close the File then return the  Free ram
            return (ram - fRam);
        }

    }

    return -1;

}

//Lets return the Used memory from /proc/meminfo in MB
double htSystem::memUMB(){
    const double megabyte = 1024;
    FILE *meminf = fopen("/proc/meminfo", "r"); //Open for read /proc/meminfo
    if(meminf == NULL){
        //if the file doesn't exist lets error out and let the user know
        cout <<"ERROR: Can't find '/proc/meminfo'" << endl;
        return -1;
    }

    char line[256]; //This will be to read the lines of the file
    while(fgets(line, sizeof(line), meminf)){
        int ram, fRam; //Holder for Ram amount
        if(sscanf(line, "MemTotal: %d kB", &ram) == 1){} //Pull the Decimal value from the MemFree Line
        if(sscanf(line, "MemFree: %d kB", &fRam) == 1) //Pull the Decimal Value from the MemFree
        {
            fclose(meminf); //Lets Close the File then return the  Free ram
            return (ram - fRam) / megabyte;
        }

    }

    return -1;

}


//Lets return the Used memory from /proc/meminfo in GB
double htSystem::memUGB(){
    const double gigabyte = 1024 * 1024;
    FILE *meminf = fopen("/proc/meminfo", "r"); //Open for read /proc/meminfo
    if(meminf == NULL){
        //if the file doesn't exist lets error out and let the user know
        cout <<"ERROR: Can't find '/proc/meminfo'" << endl;
        return -1;
    }

    char line[256]; //This will be to read the lines of the file
    while(fgets(line, sizeof(line), meminf)){
        int ram, fRam; //Holder for Ram amount
        if(sscanf(line, "MemTotal: %d kB", &ram) == 1){} //Pull the Decimal value from the MemFree Line
        if(sscanf(line, "MemFree: %d kB", &fRam) == 1) //Pull the Decimal Value from the MemFree
        {
            fclose(meminf); //Lets Close the File then return the  Free ram
            return (ram - fRam) / gigabyte;
        }

    }

    return -1;

}

/*******************************End Used Memory***************************************************/

/*******************************System Uptime*****************************************************/

void htSystem::upTime(int *days, int *hours, int *minutes, int *sec){ //using pointers so that the integers in the main function get the numbers I create


    ifstream file("/proc/uptime"); //load uptime file and get ready to read

    if(!file.is_open()){ //if it can't open let the user know
        cout << "Error Opening /proc/uptime." << endl;
    }

    string line; // for the line it will read from uptime
    string up; //up is the temp to print characters from the line until we reach a ' '
    int dUp; //the int version of up

    getline(file, line); //pull the first line from the file into the line variable

    int start = 0; //always start at 0 kids unless you need to start somewhere else
    int count = line.length(); //figure out how long the line is (character count)

    while(line[start] != ' '){ //iterate through the chars until we reach a ' '

        up = up + line[start]; //add characters to up until we reach ' '
        start++;

    }

    dUp = stoi(up); //convert up to an integer

    time_t seconds(dUp); //setup a time_t variable and turn dUp into seconds
    tm *p = gmtime(&seconds); //us gmtime to break this appart

    *days = p->tm_yday; //days to days
    *hours = p->tm_hour; //set hours to hours
    *minutes = p->tm_min; //set min to min
    *sec = p->tm_sec; //set sec to seconds
    file.close();


}

/***************************End System Uptime*****************************************************/

/****************************Pull Hostname********************************************************/
string htSystem::hostPull(){
    ifstream file("/etc/hostname"); //load uptime file and get ready to read

    if(!file.is_open()){ //if it can't open let the user know
        cout << "Error Opening /proc/uptime." << endl;
    }

    string line; // for the line it will read from uptime
    string up; //up is the temp to print characters from the line until we reach a ' '


    getline(file, line); //pull the first line from the file into the line variable

    file.close();
    return line;

}
/*********************************END Pull Hostname***********************************************/

/*********************************OS-Pull*********************************************************/
string htSystem::osPull(){

    ifstream file("/etc/os-release"); //load uptime file and get ready to read

    if(!file.is_open()){ //if it can't open let the user know
        cout << "Error Opening /proc/uptime." << endl;
    }

    string line; // for the line it will read from uptime
    string up; //up is the temp to print characters from the line until we reach a ' '


    getline(file, line); //pull the first line from the file into the line variable

    line.erase(0, 6);  //remove the first 6 characters from the line NAME="
    line.erase(line.end()-1); //remove the last character from the line which is the "

    file.close();
    return line;

}
/*********************************End OS-Pull*****************************************************/

/************************************Kernal Pull**************************************************/

string htSystem::kernPull(){

    ifstream file("/proc/version"); //load uptime file and get ready to read

    if(!file.is_open()){ //if it can't open let the user know
        cout << "Error Opening /proc/uptime." << endl;
    }

    string line; // for the line it will read from uptime
    string up; //up is the temp to print characters from the line until we reach a ' '
    int ctr = 0;
    int lineEnd;
    getline(file, line); //pull the first line from the file into the line variable

    line.erase(0, 14);  //remove the first 6 characters from the line NAME="
    line.erase(line.end()-1); //remove the last character from the line which is the "

    while(line[ctr] != ' '){ //lets use this to find where the characters begin after the actual kernel version. (first space after kernel version)
        ctr++;

    }
    lineEnd = line.length(); //get lenght of the current line after first erase
    line.erase(ctr, lineEnd-1); //remove trailing info
    file.close(); //close out the file
    return line;
}
/**********************************End Kernal Pull************************************************/

/*************************************CPU Usage***************************************************/
double htSystem::cpuUse(){

    ifstream file("/proc/stat"); //open proc/stat
    if (!file.is_open()){ //warning if file can't be opened

        cout << "Can't read /proc/stat" << endl;
        return -1;

    }

    string line; //holds the line
    getline(file, line); //get the line from file

    vector<string> words; // create a vector to hold all the words in the line
    istringstream iss(line); // create a stream to the line
    string word; //used for holding one word at a time

    while(iss >> word){ //while the stream is putting items into word
        words.push_back(word); //add word to vector words
    }

    //Get user, nice, system and idle times
    int user_time = stoi(words[1]);
    int nice_time = stoi(words[2]);
    int system_time = stoi(words[3]);
    int idle_time = stoi(words[4]);


    //Calculate the total time
    int total_time = user_time + nice_time + system_time + idle_time;

    //Calculate the CPU usage Percentage
    double cpu_usage = (double)(user_time + nice_time + system_time) / total_time * 100.f;

    file.close(); //clean up then show the result

    return cpu_usage;

}


/***********************************END CPU Usage*************************************************/
