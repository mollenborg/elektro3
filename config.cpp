#include "config.h"

config::config()
{

}

vector<string> config::readConfig()
{
    vector<string> configs;

    string line;

    ifstream myfile ("./config.les");
    if (myfile.is_open())
    {

      while ( getline (myfile,line) )
      {
          int i = 0;
          vector<string> pieces = explode(line, ';');

          for(string value: pieces) {
              configs.push_back(value);
              i++;

          }




      }
      myfile.close();
    }

    else {
        configs.push_back("Error");
    }




      return configs;
}

void config::writeConfig(vector<string> configs)
{
    // x-værdi;nkt-data;ikmax;cospi-ikmax;ikmin;cospi-ikmin
    cout << configs[0] << endl;
}

const vector<string> config::explode(const string& s, const char& c)
{
    string buff;
    buff = "";
    vector<string> v;
    int counter = 0; // Der skal tælles "

    for(auto n:s)
    {


        if(n == '\"') {
            counter ++;
        }

        if (counter == 1 && n == c)
        {
            //buff = buff + "-";
            buff+=n;
        }
        else

            if(n != c)
            {
                buff+=n;
            }

            else
                if(n == c && buff != "" && (counter == 2 || counter == 0))
                {
                    v.push_back(buff);
                    buff = "";
                    counter = 0;

                }
    }
    if(buff != "") v.push_back(buff);

    return v;
}
