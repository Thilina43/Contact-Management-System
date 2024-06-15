//CO253-Introduction to Programming and Networking for Electrical Engineering
//Mini Project- C programming
//Contact Management System
//E/19/418- T.H.B.Wakkumbura


#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


//Defining the structure
typedef struct{
    int phone;
    char name[50];
    char address[100];
    char email[50];
}contact_t;

//declaring an array to structure
contact_t contact[1000];   // This array stores contact details for up to 1000 contacts

//used functions
    void addContact(contact_t contact[],int no_of_contacts);
    void printList(contact_t contact[], int no_of_contacts);
    void searchContact(contact_t contact[],int no_of_contacts);
    void deleteContact(contact_t contact[],int *no_of_contacts);
void main(){

    //print topic and functions
    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("CONTACT MANAGEMENT SYSTEM\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    printf("0. Quit\n1. Add a new contact\n2. List all contacts\n3. Search for contact\n4. Delete a contact\n\n");

    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("ENTER OPTION [0-4]\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");


    int option=-1;
    int start=-1;
    int no_of_contacts = 0;


    while (option != 0){

    //Print after the 1st time
        if (start != -1){
            printf("------------------------------------------------------------------------------------------------------------------------\n\n");
            printf("ENTER OPTION [0-4]\n\n");
            printf("------------------------------------------------------------------------------------------------------------------------\n");

        }
        start = 0;


        scanf("%d",&option); // to get the option what user needs

        if(option==0){
            printf("Thank you!!");
            system("exit"); // exit the programme
        }
        else if(option==1){
            addContact(contact,no_of_contacts);             //add a contact
            no_of_contacts++;
        }
        else if(option==2){
            printList(contact,no_of_contacts);              //print the list
        }
        else if(option==3){
            searchContact(contact,no_of_contacts);          //search one contact
        }
        else if(option==4){
            deleteContact(contact,&no_of_contacts);          //delete contact

        }
        else{
            printf("Error!! Enter a correct value\n\n");
        }
    }
}

void addContact(contact_t contact[],int no_of_contacts){

    char tempname[50];
    char tempadd[100];

    printf("Enter your full name : ");          //to get the name
    scanf("%s",contact[no_of_contacts].name);
    fgets(tempname,50,stdin);
    strcat(contact[no_of_contacts].name,tempname);

    printf("Enter your address : ");          //to get the address
    scanf("%s",contact[no_of_contacts].address);
    fgets(tempadd,100,stdin);
    strcat(contact[no_of_contacts].address,tempadd);

    int valid = 0;
    while (!valid) {
        printf("Enter your phone number (0*********): ");
        scanf("%d", &contact[no_of_contacts].phone);

        // Check if the phone number has exactly 10 digits
        int temp = contact[no_of_contacts].phone;
        int digitCount = 0;
        while (temp != 0) {
            temp /= 10;
            ++digitCount;
        }

        if (digitCount!=9) {
            printf("Error: Phone number should have exactly 10 digits. Please try again.\n");
        } else {
            break;
        }
    }

    printf("Enter your Email address : ");
    scanf("%s",contact[no_of_contacts].email);      //enter the email

    printf("\n\nYour contact details are successfully added!!!\n\n");

}

void printList(contact_t contact[], int no_of_contacts){
    for(int i=0;i<no_of_contacts;i++){
        printf("%d\).Full name : %s\n   Address : %s\n   Phone number : +94%d\n\n   Email Address : %s\n\n\n\n",i+1,contact[i].name,contact[i].address,contact[i].phone,contact[i].email);    //to print all the contact details
    }
    if(no_of_contacts<=0){
        printf("There are no contact details\n\n");   //when list is empty
    }

}

void searchContact(contact_t contact[],int no_of_contacts){            //to search a contact details set.
    int phone_no;
    printf("Enter the phone number : ");
    scanf("%d",&phone_no);                                  //to get contact we want

    int found=0;
    for (int j=0;j<no_of_contacts;j++){
        if(contact[j].phone==phone_no){    //to  select correct phone number
            printf("\n1. Full name : %s\n2.Address : %s\n3.Phone number : +94%d\n\n4.Email Address : %s\n\n\n\n",contact[j].name,contact[j].address,contact[j].phone,contact[j].email);    //to print selected contact details
            found=1;
            break;


        }
    }
    if(!found){
        printf("Contact details not found. Please check the number you entered and try again\n\n");   //when entered contact number dosen't match to any detail set
    }

}

void deleteContact(contact_t contact[],int *no_of_contacts){
    int phone_no;
    printf("Enter the phone number : ");
    scanf("%d",&phone_no);            // to get the number that user want to delete

    int found=0;
    for (int i=0;i<*no_of_contacts;i++){
        if(contact[i].phone==phone_no){     //to find the correct contact
            found=1;
            for(int j=i;j<(*no_of_contacts-1);j++){
                contact[j]=contact[j+1];      // to shift all the contact detail list to fill the deleted contact
            }
            (*no_of_contacts)-=1;
            printf("Contact deleted successfully\n\n");
            break;
        }
    }
    if(!found){
        printf("Contact details not found. Please check the number you entered and try again\n\n");   //when entered contact number dosen't match to any detail set
    }


}
