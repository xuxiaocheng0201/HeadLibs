#ifndef HLS_CONFIGURATION_H
#define HLS_CONFIGURATION_H

#define VariableName(a) (#a)

#include "common/fstream.h"
#include "common/pair.h"
#include "common/string.h"
#include "common/vector.h"

#include "string_operate/character_escape.h"
#include "string_operate/string_dislodge.h"
#include "string_operate/turn_big_small.h"
#ifdef HLS_LOGGER_H
#include "string_operate/turn/turn_string.h"
#endif

string config_path="config.sxc";
//.sxc means  the Structure of Xuxiaocheng's Configuration file

#define CONFIGURATION_NAME 1
#define CONFIGURATION_NOTE 2
#define CONFIGURATION_TYPE 3
#define CONFIGURATION_VALUE 4

class Configuration
{
	private:
		vector< pair<pair<string,string>,pair<string,string> > > config_list;
		//                name   note         type   value
		/*
			* type=="B": bool
			* type=="I": int
			* type=="U": unsigned long long
			* type=="D": double
			* type=="S": string
		*/
	public:
	/*	Delete Configuration.
		* Function:
			* Delete the cached configuration.
		* Parameter:
			* none
		* Return value:
			* none
	*/	void clear();

	/*	Get Configuration.
		* Function:
			* Get part value of the cached configuration.
		* Parameter:
			* unsigned int(slot),int(part)
				* int(part) must be between 1 and 4
				* 1 equals CONFIGURATION_NAME
					* get the name of slot-th configuration
				* 2 equals CONFIGURATION_NOTE
					* get the note of slot-th configuration
				* 3 equals CONFIGURATION_TYPE
					* get the type of slot-th configuration
				* 4 equals CONFIGURATION_VALUE
					* get the value of slot-th configuration
		* Return value:
			* the part you questioned
	*/	string get(unsigned int slot,int part);
	
	/*	Get Configuration size.
		* Function:
			* Get configuration size.
		* Parameter:
			* none
		* Return value:
			* config_list.size()
	*/	unsigned int size();

	/*	Add Configuration.
		* Function:
			* Add a new configuration.
		* Parameter:
			* string(name),string(note),string(type),string(value)
		* Return value:
			* 1
				* success.
			* 0
				* failure.
	*/	bool add(string name,string note,string type,string value);
		
	/*	Write Configuration.
		* Function:
			* Save the configuration to a file.
		* Parameter:
			* When includes logger.h
				* none
					* write configuration to config_path
					* log process at log_path
				* string(new_config_path),string(new_log_path)
					* write configuration to new_config_path
					* log process at new_log_path
			* Else
				* none
					* write configuration to config_path.
				* string(new_config_path)
					* write configuration to new_config_path.
		* Return value:
			* 1
				* success.
			* 0
				* failure.
	*/	bool write();
		bool write(string new_config_path);
		#ifdef HLS_LOGGER_H
		bool write(string new_config_path,string new_log_path);
		#endif

	/*	Read Configuration.
		* Function:
			* Read the configuration from a file.
		* Parameter:
			* When includes logger.h
				* none
					* read configuration from config_path
					* log process at log_path
				* string(new_config_path),string(new_log_path)
					* read configuration from new_config_path
					* log process at new_log_path
			* Else
				* none
					* read configuration from config_path.
				* string(new_config_path)
					* read configuration from new_config_path.
		* Return value:
			* 1
				* success.
			* 0
				* failure.
	*/	bool read();
		bool read(string new_config_path);
		#ifdef HLS_LOGGER_H
		bool read(string new_config_path,string new_log_path);
		#endif
		
	/*	Fix Configuration.
		* Function:
			* Fix this configuration head blank.
		* Parameter:
			* When includes logger.h
				* none
					* fix configuration
					* log process at log_path
				* string(new_log_path)
					* fix configuration
					* log process at new_log_path
			* Else
				* none
					* Fix configuration.
		* Return value:
			* 1
				* success.
			* 0
				* failure.
	*/	void fix();
		#ifdef HLS_LOGGER_H
		void fix(string new_log_path);
		#endif
};

bool check_config_type(pair<string,string>& config)
{
	if(config.first!="B" && config.first!="I" && config.first!="U" && config.first!="D" && config.first!="S")
	{
		#ifdef HLS_LOGGER_H
		logger("WARN","[CONFIGURATION.H][check_config_type][config.first]="+config.first+" error. It must be B, I, U, D, or S. Changing it to S");
		#endif
		config.first="S";
	}
	if(config.first=="B")
	{
		if(config.second.size()==0)
		{
			config.second="false";
			return 1;
		}
		string value=string_dislodge(turn_small(config.second),STRING_DISLODGE_LETTER_SMALL|STRING_DISLODGE_NUMBER|STRING_DISLODGE_CONTRARY);
//		if(value=="false")
//			config.second="false";
		if(value=="flase")	//usual spelling error
			config.second="false";
		if(value=="no")		//speical spelling
			config.second="false";
		if(value=="not")	//speical spelling
			config.second="false";
		if(value=="dont")	//speical spelling
			config.second="false";
//		if(value=="true")
//			config.second="true";
		if(value=="ture")	//usual spelling error
			config.second="true";
		if(value=="ok")		//speical spelling
			config.second="true";
		if(value=="sure")	//speical spelling
			config.second="true";
		if(value=="right")	//speical spelling
			config.second="true";
		if(value=="0")
			config.second="false";
		if(value=="1")
			config.second="true";
		if(config.second!="false" && config.second!="true")
			return 0;
	}
	if(config.first=="I")
	{
		if(config.second.size()==0)
		{
			config.second="0";
			return 1;
		}
		unsigned int i=0;
		bool negative=0;
		for(;i<config.second.size();i++)
		{
			if(config.second[i]=='-')
			{
				negative=!negative;
				continue;
			}
			if(config.second[i]=='+')
				continue;
			break;
		}
		string value="";
		for(;i<config.second.size();i++)
			if('0'<=config.second[i] && config.second[i]<='9')
				value+=config.second[i];
		config.second=string(negative?"-":"")+value;
	}
	if(config.first=="U")
	{
		if(config.second.size()==0)
		{
			config.second="0";
			return 1;
		}
		string value="";
		for(unsigned int i=0;i<config.second.size();i++)
			if('0'<=config.second[i] && config.second[i]<='9')
				value+=config.second[i];
		config.second=value;
	}
	if(config.first=="D")
	{
		if(config.second.size()==0)
		{
			config.second="0.0";
			return 1;
		}
		unsigned int d=config.second.size()-1;
		for(unsigned int i=d;i>0;i--)
			if(config.second[i]=='.')
				d=i;
		string value_1="";
		for(unsigned int i=0;i<d;i++)
			if('0'<=config.second[i] && config.second[i]<='9')
				value_1+=config.second[i];
		if(value_1=="")
			value_1="0";
		string value_2="";
		for(unsigned int i=d;i<config.second.size();i++)
			if('0'<=config.second[i] && config.second[i]<='9')
				value_2+=config.second[i];
		if(value_2=="")
			value_2="0";
		config.second=value_1+"."+value_2;
	}
	return 1;
}

void Configuration::clear()
{
	config_list.clear();
	return;
}

string Configuration::get(unsigned int slot,int part)
{
	if(slot>=config_list.size())
	{
		#ifdef HLS_LOGGER_H
		logger("WARN","[CONFIGURATION.H][GET][slot] is bigger than config_list.size()!");
		logger("DEBUG","[CONFIGURATION.H][GET][solt]="+turn_string(slot)+". config_list.size()="+turn_string(config_list.size())+". [part]="+turn_string(part)+".");
		#endif
		if(part==CONFIGURATION_NAME)
		{
			#ifdef HLS_LOGGER_H
			logger("ERROR","[CONFIGURATION.H][GET]Return null.");
			#endif
			return "";
		}
		if(part==CONFIGURATION_NOTE)
		{
			#ifdef HLS_LOGGER_H
			logger("ERROR","[CONFIGURATION.H][GET]Return null.");
			#endif
			return "";
		}
		if(part==CONFIGURATION_TYPE)
		{
			#ifdef HLS_LOGGER_H
			logger("ERROR","[CONFIGURATION.H][GET]Return \"S\".");
			#endif
			return "S";
		}
		if(part==CONFIGURATION_VALUE)
		{
			#ifdef HLS_LOGGER_H
			logger("ERROR","[CONFIGURATION.H][GET]Return null.");
			#endif
			return "";
		}
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CONFIGURATION.H][GET][part]="+turn_string(part)+", which is out of bord.");
		#endif
		return "";
	}
	if(part==CONFIGURATION_NAME)
		return config_list[slot].first.first;
	if(part==CONFIGURATION_NOTE)
		return config_list[slot].first.second;
	if(part==CONFIGURATION_TYPE)
		return config_list[slot].second.first;
	if(part==CONFIGURATION_VALUE)
		return config_list[slot].second.second;
	#ifdef HLS_LOGGER_H
	logger("ERROR","[CONFIGURATION.H][GET][part]="+turn_string(part)+", which is out of bord.");
	#endif
	return "";
}

unsigned int Configuration::size()
{
	return config_list.size();
}

bool Configuration::add(string name,string note,string type,string value)
{
	pair<string,string> config;
	config.first=type;
	config.second=value;
	if(!check_config_type(config))
		return 0;
	for(unsigned int i=0;i<config_list.size();i++)
		if(config_list[i].first.first==name)
		{
			#ifdef HLS_LOGGER_H
			logger("WARN","[CONFIGURATION.H][ADD][name] error. It existed, you may mean change? It is \""+name+"\".");
			logger("DEBUG","[CONFIGURATION.H][ADD]Changing config_list["+turn_string(i)+"] to <name,note,type,value>=<\""+name+"\",\""+note+"\",\""+config.first+"\",\""+config.second+"\">.");
			#endif
			config_list[i]=make_pair(make_pair(name,note),config);
			return 1;
		}
	config_list.push_back(make_pair(make_pair(name,note),config));
	return 1;
}

bool Configuration::write()
{
	ofstream w_config(config_path.c_str());
	if(!w_config)
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CONFIGURATION.H][WRITE]Open configuration file \""+config_path+"\" failed.");
		#endif
		return 0;
	}
	for(unsigned int i=0;i<config_list.size();i++)
	{
		string name="";
		for(unsigned int j=0;j<config_list[i].first.first.size();j++)
			name+=character_escape(config_list[i].first.first[j]);
		string note="";
		for(unsigned int j=0;j<config_list[i].first.second.size();j++)
			note+=character_escape(config_list[i].first.second[j]);
		string value="";
		for(unsigned int j=0;j<config_list[i].second.second.size();j++)
			value+=character_escape(config_list[i].second.second[j]);
		w_config<<"name: "<<name<<endl;
		w_config<<"note: "<<note<<endl;
		w_config<<"type: "<<config_list[i].second.first<<endl;
		w_config<<"value: "<<value<<endl;
		w_config<<endl;
	}
	w_config.close();
	#ifdef HLS_LOGGER_H
	logger("DEBUG","[CONFIGURATION.H][WRITE]Saved "+turn_string(config_list.size())+" configuration"+((config_list.size()>1)?(""):("s"))+".");
	#endif
	return 1;
}

bool Configuration::write(string new_config_path)
{
	string old_config_path=config_path;
	config_path=new_config_path;
	bool res=write();
	config_path=old_config_path;
	return res;
}

#ifdef HLS_LOGGER_H
bool Configuration::write(string new_config_path,string new_log_path)
{
	string old_config_path=config_path;
	string old_log_path=log_path;
	config_path=new_config_path;
	log_path=new_log_path;
	bool res=write();
	config_path=old_config_path;
	log_path=old_log_path;
	return res;
}
#endif

bool Configuration::read()
{
	ifstream r_config(config_path.c_str());
	if(!r_config)
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CONFIGURATION.H][READ]Open configuration file \""+config_path+"\" failed.");
		#endif
		return 0;
	}
	string line;
	line.clear();
	#ifdef HLS_LOGGER_H
	unsigned int line_number=0;
	#endif
	bool first_config=1;
	pair<pair<string,string>,pair<string,string> > temp_config;
	temp_config.first.first="[example]Unknow Name";
	temp_config.first.second="[example]This is a note to explain what the value is used to do.";
	temp_config.second.first="S";
	temp_config.second.second="[example]A string value for example.";
	while(getline(r_config,line))
	{
		#ifdef HLS_LOGGER_H
		line_number++;
		#endif
		if(line=="")
			continue;
		string part="";
		string _get="";
		bool part_complete=0;
		for(unsigned int i=0;i<line.size();i++)
		{
			if(line[i]==':' && !part_complete)
			{
				part_complete=1;
				i++;
				continue;
			}
			if(part_complete)
				_get+=line[i];
			else
				part+=line[i];
		}
		string get="";
		for(unsigned int j=0;j<_get.size();j++)
		{
			if(_get[j]=='\\' && j<_get.size()-1)
			{
				string character=(string)"\\"+_get[j+1];
				if(character_escape(character)!=0)
				{
					get+=character_escape(character);
					j++;
					continue;
				}
			}
			get+=_get[j];
		}
		if(part=="name")
		{
			if(!first_config)
			{
				config_list.push_back(temp_config);
				temp_config.first.second="[example]This is a note to explain what the value is used to do.";
				temp_config.second.first="S";
				temp_config.second.second="[example]A string value for example.";
			}
			else
				first_config=0;
			temp_config.first.first=get;
			continue;
		}
		if(part=="note")
		{
			temp_config.first.second=get;
			continue;
		}
		if(part=="type")
		{
			if(get!="B" && get!="I" && get!="U" && get!="D" && get!="S")
			{
				#ifdef HLS_LOGGER_H
				logger("ERROR","[CONFIGURATION.H][READ]Configuration file error in \""+config_path+"\". [type]=\""+get+"\" error in line "+turn_string(line_number)+". Turn to S.");
				#endif
				get="S";
			}
			temp_config.second.first=get;
			continue;
		}
		if(part=="value")
		{
			pair<string,string> config;
			config.first=temp_config.second.first;
			config.second=get;
			if(!check_config_type(config))
			{
				#ifdef HLS_LOGGER_H
				logger("ERROR","[CONFIGURATION.H][READ]Configuration file error in \""+config_path+"\". [value]=\""+get+"\" error in line "+turn_string(line_number)+". Turn to \"error\".");
				#endif
				config.second="error";
			}
			temp_config.second=config;
			continue;
		}
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CONFIGURATION.H][READ]Configuration file error in \""+config_path+"\". Can't discern the part \""+part+"\" in line "+turn_string(line_number)+".");
		#endif
	}
	config_list.push_back(temp_config);
	return 1;
}

bool Configuration::read(string new_config_path)
{
	string old_config_path=config_path;
	config_path=new_config_path;
	bool res=read();
	config_path=old_config_path;
	return res;
}

#ifdef HLS_LOGGER_H
bool Configuration::read(string new_config_path,string new_log_path)
{
	string old_config_path=config_path;
	string old_log_path=log_path;
	config_path=new_config_path;
	log_path=new_log_path;
	bool res=read();
	config_path=old_config_path;
	log_path=old_log_path;
	return res;
}
#endif

void Configuration::fix()
{
	for(unsigned int i=0;i<config_list.size();i++)
	{
		string new_name="";
		bool name_head_blank=1; 
		for(unsigned int j=0;j<config_list[i].first.first.size();j++)
		{
			if(config_list[i].first.first[j]==' ' && name_head_blank)
				continue;
			name_head_blank=0;
			new_name+=config_list[i].first.first[j];
		}
		config_list[i].first.first=new_name;
		
		string new_note="";
		bool note_head_blank=1; 
		for(unsigned int j=0;j<config_list[i].first.second.size();j++)
		{
			if(config_list[i].first.second[j]==' ' && note_head_blank)
				continue;
			note_head_blank=0;
			new_note+=config_list[i].first.second[j];
		}
		config_list[i].first.second=new_note;
		
		string new_value="";
		bool value_head_blank=1; 
		for(unsigned int j=0;j<config_list[i].second.second.size();j++)
		{
			if(config_list[i].second.second[j]==' ' && value_head_blank)
				continue;
			value_head_blank=0;
			new_value+=config_list[i].second.second[j];
		}
		config_list[i].second.second=new_value;
	}
	return;
}

#ifdef HLS_LOGGER_H
void Configuration::fix(string new_log_path)
{
	string old_log_path=log_path;
	log_path=new_log_path;
	fix();
	log_path=old_log_path;
	return;
}
#endif

#endif

