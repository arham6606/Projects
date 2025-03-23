#include "functions.h"

int main()
{
    // for computer class
    Computer c1;
    c1.setModel("Gaming PC");
    c1.setProcessor("Intel", 8);
    cout << "Computer Information" << endl;
    cout << "Model: " << c1.getModel() << endl;
    cout << "Brand: " << c1.getProcessor().getBrand() << endl;
    cout << "Cores: " << c1.getProcessor().getCores() << endl;
    if (c1.isGamingComputer())
    {
        cout << "It is a gaming computer" << endl;
    }
    else
    {
        cout << "Not a Gaming Computer" << endl;
    }

    cout << endl;

    // for university class
    University uni;
    Professor p1, p2;
    p1.setName("Dr. Smith");
    p1.setSubject("Mathematics");
    p2.setName("Dr. John");
    p2.setSubject("Physics");
    uni.addProfessor(&p1);
    uni.addProfessor(&p2);
    cout << "Professor Count: " << uni.countProfessors() << endl;
    cout << "Name: " << uni.getProfessor(0)->getName() << endl;
    if (uni.getProfessor(1)->teachesSubject("Physics") == true)
    {
        cout << "Name: " << uni.getProfessor(1)->getName() << endl;
    }

    cout << endl;

    // for hospital  classs
    Hospital h;
    Doctor d;
    Patient p;
    d.setName("Dr. Adams");
    d.setSpecialization("Cardiology");
    p.setName("Alice");
    p.setAge(25);
    d.assignPatient(&p);
    h.addDoctor(&d);
    cout << "Doctors Count: " << h.countDoctors() << endl;
    cout << "Patient for this doctor: " << h.getDoctor(0)->countPatients() << endl;
    cout << "Name of Patient: " << h.getDoctor(0)->getPatient(0)->getName() << endl;

    cout << endl;

    // for music album
    MusicAlbum alb;
    alb.setAlbumName("Greatest Hits");
    alb.addSong("Song A", 4.5);
    alb.addSong("Song B", 6.0);
    cout << "Album Name: " << alb.getAlbumName() << endl;
    cout << "Numeber of Songs: " << alb.countSongs() << endl;
    if (alb.getSong(1).isLongSong() == true)
    {
        cout << "Duration is above 5 minutes" << endl;
    }

    cout << endl;

    // for restaurant class
    Restaurant r;
    r.setRestaurantName("Fine Dining");
    r.setMenu("Steak", 25.0);
    r.setMenu("Salad", 10.0);
    cout << "Name: " << r.getRestaurantName() << endl;
    if (r.hasExpensiveDishes() == true)
    {
        cout << "Yes the dishes are expensive" << endl;
    }
    else
    {
        cout<<"Dishes are in range"<<endl;
    }
}