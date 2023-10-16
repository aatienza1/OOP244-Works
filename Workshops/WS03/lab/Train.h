
// -----------------------------------------------------------
// Name:Alicia Atienza                 Date:9/29/2023            StudentID: 38782074		email:aatienza1@myseneca.ca
//*********************************************************************** /
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.#ifndef SDDS_TRAIN_H
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {
    class Train {

    private:
        char* m_trainName;
        int m_noOfPassengers;
        int m_departTime;

    public:
        void initialize();
        bool validTime(int value) const;
        bool validNoOfPassengers(int value) const;
        void set(const char* name);
        void set(int noOfPassengers, int departure);
        void set(const char* name, int noOfPassengers, int departure);
        void finalize();
        bool isInvalid() const;
        int noOfPassengers() const;
        const char* getName() const;
        int getDepartureTime() const;
        void display() const;
    };
}

#endif //SDDS_TRAIN_H

