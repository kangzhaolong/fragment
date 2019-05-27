#include <iostream>
#include <json/json.h>
#include <curl/curl.h>
#include <curl/easy.h>


using namespace std;

int main(int argc, char** argv)
{
	Json::Reader r ;
	curl_global_init(CURL_GLOBAL_ALL);
	CURL* c = curl_easy_init();
	
	if(c)
	{ 
		//curl_easy_setopt(curl_handle, CURLOPT_URL, url);
		//set down load url 
		//curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, save_file);
		//set download file
		//curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, recive_data_fun);
		//set call back fun 
		//curl_easy_setopt(curl_handle, CURLOPT_HEADERFUNCTION, read_head_fun);
		//set call back fun
		#ifdef CURL_DEBUG 
			curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1); 
		#endif //start down load 
		//res = curl_easy_perform(curl_handle); 
		//cout<<"curl fetch code "<<res<<endl();
		
		
		
		cout<<"curl version:"<<curl_version()<<endl;
		
	}

	cout<<"Hello "<<endl;
	
	curl_easy_cleanup(c);
	curl_global_cleanup();
	return 0;
}
