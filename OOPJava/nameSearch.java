public int search(String searchTerm){
     int index = 0;
     boolean found = false;

     while(!found && index < firstNames.size()){
          String name = firstNames.get(index);
          if(name.contains(searchTerm)){
               found = true;
          }
          else {
               index++;
          }
     }
     
     if(!found){
          return - 1;
     }
     else {
          return index;
     }
}
