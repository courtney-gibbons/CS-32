//#include <iostream>
//#include <string>
//using namespace std;
//
//enum CallType {
//    VOICE, TEXT
//};
//
//// MY CODE START ////////////////////////////////////////////////////////////////////////
//class Medium {
//public:
//    Medium(string id) : m_id(id) { }
//    virtual ~Medium() { }
//    virtual string connect() const = 0;
//    string id() const {
//        return m_id;
//    }
//    virtual string transmit(string msg) const {
//        return "text: " + msg;
//    }
//private:
//    string m_id;
//};
//
//class TwitterAccount : public Medium {
//public:
//    TwitterAccount(string id) : Medium(id) { }
//    virtual ~TwitterAccount() {
//        cout << "Destroying the Twitter account " << id() << "." << endl;
//    }
//    virtual string connect() const {
//        return "Tweet";
//    }
//private:
//};
//
//class Phone : public Medium {
//public:
//    Phone(string id, CallType callType) : Medium(id), m_callType(callType) { }
//    virtual ~Phone() {
//        cout << "Destroying the phone " << id() << "." << endl;
//    }
//    virtual string connect() const {
//        return "Call";
//    }
//    virtual string transmit(string msg) const {
//        if (m_callType == VOICE) {
//            return "voice: " + msg;
//        } else {
//            return "text: " + msg;
//        }
//    }
//private:
//    CallType m_callType;
//};
//
//class EmailAccount : public Medium {
//public:
//    EmailAccount(string id) : Medium(id) { }
//    virtual ~EmailAccount() {
//        cout << "Destroying the email account " << id() << "." << endl;
//    }
//    virtual string connect() const {
//        return "Email";
//    }
//private:
//};
//// MY CODE END ////////////////////////////////////////////////////////////////////////
//
//void send(const Medium* m, string msg)
//{
//    cout << m->connect() << " using id " << m->id()
//         << ", sending " << m->transmit(msg) << endl;
//}
//
//int main()
//{
//    Medium* media[4];
//    media[0] = new TwitterAccount("UCLABruinAlert");
//      // Phone users may prefer messages to be left as voice or text.
//    media[1] = new Phone("(310) 825 3894", VOICE);
//    media[2] = new Phone("(213) 389 9060", TEXT);
//    media[3] = new EmailAccount("jbroon@ucla.edu");
//
//    cout << "Send the message." << endl;
//    for (int k = 0; k < 4; k++)
//        send(media[k], "Major power outage in West L.A.");
//
//      // Clean up the media before exiting
//    cout << "Cleaning up." << endl;
//    for (int k = 0; k < 4; k++)
//        delete media[k];
//}
//
///*
// Send the message.
// Tweet using id UCLABruinAlert, sending text: Major power outage in West L.A.
// Call using id (310) 825 3894, sending voice: Major power outage in West L.A.
// Call using id (213) 389 9060, sending text: Major power outage in West L.A.
// Email using id jbroon@ucla.edu, sending text: Major power outage in West L.A.
// Cleaning up.
// Destroying the Twitter account UCLABruinAlert.
// Destroying the phone (310) 825 3894.
// Destroying the phone (213) 389 9060.
// Destroying the email account jbroon@ucla.edu.
// */
