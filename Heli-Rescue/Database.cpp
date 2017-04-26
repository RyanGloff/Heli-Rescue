#include "Database.h"

#include <stdlib.h>
#include <iostream>

Database::Database (std::string userName,
                    std::string password,
                    std::string schema,
                    std::string IPAdress) {
  this->userName = userName;
  this->password = password;
  this->schema = schema;
  this->IPAdress = IPAdress;
  try {
    // Creating a connection
    driver = get_driver_instance();
    con = driver->connect("tcp://" + IPAdress, userName, password);

    // Connect to the Database
    con->setSchema(schema);
  } catch (sql::SQLException &e) {
    std::cout << "#ERR: SQLException in " << __FILE__;
    std::cout << "()" << __FUNCTION__ << ") on line" << __LINE__ << std::endl;
    std::cout << "#ERR: " << e.what();
    std::cout << " (MySQL error code: " << e.getErrorCode();
    std::cout << ", SQLState: " << e.getSQLState() << ")" << std::endl;
  }
}
Database::~Database() {
  delete res;
  delete stmt;
  delete con;
}

sql::ResultSet* Database::executeQuery (std::string query) {
  try {
    stmt = con->createStatement();
    res = stmt->executeQuery(query);
  } catch (sql::SQLException &e) {
    std::cout << "#ERR: SQLException in " << __FILE__;
    std::cout << "()" << __FUNCTION__ << ") on line" << __LINE__ << std::endl;
    std::cout << "#ERR: " << e.what();
    std::cout << " (MySQL error code: " << e.getErrorCode();
    std::cout << ", SQLState: " << e.getSQLState() << ")" << std::endl;
  }
  return res;
}

void Database::executePrepStatement (std::string stmt) {
  try {
    sql::PreparedStatement* prep = con->prepareStatement(stmt);
    prep->execute();
  } catch (sql::SQLException &e) {
    std::cout << "#ERR: SQLException in " << __FILE__;
    std::cout << "()" << __FUNCTION__ << ") on line" << __LINE__ << std::endl;
    std::cout << "#ERR: " << e.what();
    std::cout << " (MySQL error code: " << e.getErrorCode();
    std::cout << ", SQLState: " << e.getSQLState() << ")" << std::endl;
  }
}

std::string Database::getUserName () {
  return userName;
}
std::string Database::getPassword () {
  return password;
}
std::string Database::getSchema () {
  return schema;
}
std::string Database::getIP () {
  return IPAdress;
}

void Database::setSchema (std::string schema) {
  schema = schema;
  con->setSchema(schema);
}
