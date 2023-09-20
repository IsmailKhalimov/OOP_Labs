#include <iostream>

#include "task.h"

using namespace std;


int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    int answer = toBinary(a, b);
    if (answer == -1){
        cout << "Second element should be greater than first";
        return 0;
    }
    cout << answer;
    return 0;
}