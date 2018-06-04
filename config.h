#ifndef CONFIG_H
#define CONFIG_H


#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class config
{
public:
    config();
    vector<string> readConfig();
    void writeConfig(vector<string> configs);

private:
    const vector<string> explode(const string& s, const char& c);

};

#endif // CONFIG_H
