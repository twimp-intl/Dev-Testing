#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function to write data received from the server
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size = size * nmemb;
    // Print the response data
    printf("%.*s", (int)total_size, (char*)contents);
    return total_size;
}

int main(void) {
    CURL *curl;
    CURLcode res;

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        // Set the URL of the REST API
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.example.com/resource");

        // Specify the callback function to handle the response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }

    // Global libcurl cleanup
    curl_global_cleanup();

    return 0;
}
