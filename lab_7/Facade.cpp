#include <iostream>
#include <string>

using namespace std;

class Projector {
public:
    void TurnOn() {
        cout << "Projector: turned on" << endl;
    }

    void TurnOff() {
        cout << "Projector: turned off" << endl;
    }
};

class Amplifier {
public:
    void TurnOn() {
        cout << "Amplifier: turned on" << endl;
    }

    void SetVolume(int level) {
        cout << "Amplifier: volume set to " << level << endl;
    }

    void TurnOff() {
        cout << "Amplifier: turned off" << endl;
    }
};

class DVDPlayer {
public:
    void TurnOn() {
        cout << "DVD Player: turned on" << endl;
    }

    void Play(string movie) {
        cout << "DVD Player: playing \"" << movie << "\"" << endl;
    }

    void TurnOff() {
        cout << "DVD Player: turned off" << endl;
    }
};

class Lights {
public:
    void Dim(int level) {
        if (level < 0 || level > 100) {
            cout << "Invalid light level: must be between 0 and 100." << endl;
            return;
        }
        cout << "Lights: dimmed to " << level << "%" << endl;
    }
};

class HomeTheaterFacade {
private:
    Projector* _projector;
    Amplifier* _amplifier;
    DVDPlayer* _dvdPlayer;
    Lights* _lights;

public:
    HomeTheaterFacade() {
        _projector = new Projector();
        _amplifier = new Amplifier();
        _dvdPlayer = new DVDPlayer();
        _lights = new Lights();
    }

    void WatchMovie(string movieName) {
        _lights->Dim(20);
        _projector->TurnOn();
        _amplifier->TurnOn();
        _amplifier->SetVolume(5);
        _dvdPlayer->TurnOn();
        _dvdPlayer->Play(movieName);
    }

    void EndMovie() {
        _dvdPlayer->TurnOff();
        _amplifier->TurnOff();
        _projector->TurnOff();
        _lights->Dim(100);
    }
};

int main() {
    HomeTheaterFacade* theater = new HomeTheaterFacade();
    
    theater->WatchMovie("The Matrix");
    cout << "Enjoy your movie!" << endl;
    theater->EndMovie();

    return 0;
}
