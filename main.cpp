/*
* TODO:
 * implementat biblioteca
 * carti:
 *  - autor
 *  - titplu
 *  - an aparitie
 *  clasa carte + repo
 *  repo - CRUD + template + STD
 *  STL **coada cu prioritari
 *  imprumut cate -> dupa titlu/autor/etc. -> verif daca e valabila (neimprumutata) -> nu mai e valabila
 *  -> se retine pers. care a imprumutat -> show all cu detalii imprumut
 *  retur
*/

#include "Tests/TestDomain.h"
#include "Tests/TestRepo.h"
#include "Service/Service.h"
#include "UI/Console.h"

int main() {
//    tests
//    TestDomain::test_domain();
//    TestRepo test_repo;
//    test_repo.test_all();
//
    RepoSTL<Book> myRepo("C:\\Users\\butea\\CLionProjects\\Books\\in.txt","C:\\Users\\butea\\CLionProjects\\Books\\in.txt");
    Service myService(myRepo);
    Console myConsole(myService);
    myConsole.runUI();
    return 0;
}
