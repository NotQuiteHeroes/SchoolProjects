Iterator<String> it = firstNames.iterator();
while(it.hasNext()){
     String n = it.next();
     String name = n.getName();
     if(name.equals(nameToDelete)){
          it.remove();
     }
}
