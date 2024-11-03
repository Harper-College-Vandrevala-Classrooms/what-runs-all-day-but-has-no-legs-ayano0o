#include <ctime>
#include <chrono>
#include <cmath>

using namespace std;

class Time {
  private:
   bool is_running;
   int elapsed_seconds;
   chrono::time_point<chrono::system_clock> start_time;
   chrono::time_point<chrono::system_clock> stop_time;

  public:
   Time() : is_running(false), elapsed_seconds(0) {}
   void start();
   void stop();
   int elapsed();
   int getTime() const;

};

void Time::start()
{
  if (!is_running) {
            start_time = chrono::system_clock::now();
            is_running = true;
            elapsed_seconds = 0;
            cout << "Timer started.\n";
        } else {
            cout << "Timer is already running.\n";
        }
}

void Time::stop()
{
  if (is_running) {
            stop_time = chrono::system_clock::now();
            is_running = false;
            elapsed_seconds = chrono::duration_cast<chrono::seconds>(stop_time - start_time).count();
            cout << "Timer stopped.\n";
        } else {
            cout << "Timer is not running.\n";
        }
}

int Time::elapsed()
{
     if (is_running) {
            auto current_time = chrono::system_clock::now();
            return chrono::duration_cast<chrono::seconds>(stop_time - start_time).count();
        } else {
            return elapsed_seconds;
        }
}

int Time::getTime() const {
    return elapsed_seconds;
}
