#include "qml.hh"

int Operation::n=0;
int Circuit::app_id=0;
const char *ident ="  ";

const char ENDL[] = {0x0A,0x00};

ostream & operator<<(ostream & out, const XmlParam & p){
 // if(!p.value.empty())
    return out << " " << p.name << "=\"" << p.value << "\"" ;
  //return out;
}

int XmlTag::tabs = 0;

ostream & operator<<(ostream & out, const XmlTag & tag){
  for(int t = 0 ; t< tag.tabs;t++) out << ident;
  out << "<" << tag.tag_name;
  for(vector<XmlParam*>::const_iterator i = tag.params.begin(); i!= tag.params.end(); i++)
    out << **i;
  if(tag.subtags.empty()){
    if(tag.empty_endtagname){
      out << ">" << ENDL;
      for(int t = 0 ; t< tag.tabs;t++) 
        out << ident;
      return out << "</" << tag.tag_name << ">" << ENDL ;
    }else{
    
      return out << "/>" << ENDL ;
    }
  }

  out << ">" << ENDL ;
  tag.tabs++;
  for(vector<XmlTag*>::const_iterator i = tag.subtags.begin(); i!=tag.subtags.end(); i++)
    out << **i;
  tag.tabs--;
  for(int t = 0 ; t< tag.tabs;t++) 
    out << ident;
  return out << "</" << tag.tag_name << ">" << ENDL ;
}

ostream & operator<<(ostream & out, const Comment & tag){
	
  for(int t = 0 ; t< tag.tabs;t++) 
    out << ident;
  return out << "<!-- " << tag.tag_name << " -->" << ENDL ;
}
