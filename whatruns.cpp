#include <iostream>
#include <cassert>
#include "whatruns.hpp"

using namespace std;

void testQuickStartStop() {
    Time timer;
    timer.start();
    timer.stop();
    assert(timer.elapsed() <= 3); 
    cout << "testQuickStartStop passed :\n";
}

void testStopBeforeStart() {
    Time timer;
    timer.stop();
    assert(timer.elapsed() == 0); 
    cout << "testStopBeforeStart passed: \n";
}

void testElapsedBeforeStart() {
    Time timer;
    assert(timer.elapsed() == 0); 
    cout << "testElapsedBeforeStart passed: \n";
}

void testMultipleStarts() {
    Time timer;
    timer.start();
    timer.start(); 
    int elapsed_time1 = timer.elapsed();
    int elapsed_time2 = timer.elapsed();
    assert(elapsed_time1 == elapsed_time2); 
    cout << "testMultipleStarts passed: \n";
}



int main () {
   
   
    testQuickStartStop();
    testStopBeforeStart();
    testElapsedBeforeStart();
    testMultipleStarts();
   
   cout << "All tests passed.\n";

    Time timer;
    string input;

    cout << "Type 'start' to start the timer..." << endl;
    cin >> input;

    if (input == "start" || input == "Start" || input == "START") {
        timer.start();
    } else {
        cout << "Not a valid input to start the timer..." << endl;
        return 0;
    }

    cout << "Type 'stop' to stop the timer..." << endl;
    cin >> input;

    if (input == "stop" || input == "Stop" || input == "STOP") {
        timer.stop();
        cout << "Elapsed time: " << timer.getTime() << " seconds" << endl; 
    } else {
        cout << "Not a valid input to stop the timer..." << endl;
        return 0;
    }

    return 0;
}
