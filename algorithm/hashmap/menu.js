
Hashmap = function(){
    this.map= new Array();
}

Hashmap.prototype={
   put:function(key,value){
       this.map[key]=value;
   }
}