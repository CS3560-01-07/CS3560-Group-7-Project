#include <string>
#ifndef Header_h
#define Header_h

using namespace std;

class Transaction
{
   private:
      int transactionID;
      string dateOfTransaction;
      string timeOfTransaction;

   public:
      Transaction(const int & = 0.0, string = "", string = "");
    
      int getTransactionID() const;
      void setTransactionID(int);
    
      string getDateOfTransaction() const;
      void setDateOfTransaction(string _theDateOfTransaction);
    
      string getTimeOfTransaction() const;
      void setTimeOfTransaction(string _theTimeOfTransaction);
};

#endif /* Header_h */
