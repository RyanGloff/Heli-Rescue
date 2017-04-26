#pragma
#include <string>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

class Database {
private:
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;

  std::string userName;
  std::string password;
  std::string schema;
  std::string IPAdress;

  void init();
public:
  Database(std::string userName,
           std::string password,
           std::string schema,
           std::string IPAdress);
  ~Database();

  sql::ResultSet* executeQuery(std::string);
  void executePrepStatement(std::string);

  std::string getUserName();
  std::string getPassword();
  std::string getSchema();
  std::string getIP();

  void setSchema(std::string);

};
