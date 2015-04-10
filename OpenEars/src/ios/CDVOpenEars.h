/*
Open Ears on Cordova/Phoegap plugin

http://www.politepix.com/openears/
http://cordova.apache.org/docs/en/3.4.0/guide_platforms_ios_plugin.md.html#iOS%20Plugins

Based on:
https://github.com/rtelep/phonegap_openears
but with function & Callback names normalised for portability.

*/

#import <Cordova/CDV.h>

#import <OpenEars/OEPocketsphinxController.h>
#import <OpenEars/OEEventsObserver.h>
#import <OpenEars/OEFliteController.h>
#import <OpenEars/OELanguageModelGenerator.h>
#import <OpenEars/OELogging.h>
#import <OpenEars/OEAcousticModel.h>
#import <Slt/Slt.h>


@interface CDVOpenEars : CDVPlugin<OEEventsObserverDelegate> {
	OEPocketsphinxController *pocket_sphinx_controller;
	OEEventsObserver *openears_events_observer;
	OEFliteController *flite_controller;
    Slt *slt;
	OELanguageModelGenerator *language_model_generator;
    
	NSNumber *started_listening; // 1, 0 (yes, no)
  NSString *acoustic_model;
	NSString *current_language_model;
	NSString *current_dictionary;
	NSString *path_to_dynamic_language_model;
	NSString *path_to_dynamic_grammar;
}

// @property (nonatomic, strong) AudioSessionManager *audio_session_manager
@property (nonatomic, strong) OEPocketsphinxController *pocket_sphinx_controller;
@property (nonatomic, strong) OEEventsObserver *openears_events_observer;
@property (nonatomic, strong) OELanguageModelGenerator *language_model_generator;
@property (nonatomic, strong) OEFliteController *flite_controller;
@property (nonatomic, strong) Slt *slt;

@property (nonatomic, strong) NSNumber *started_listening;
@property (nonatomic, strong) NSString *acoustic_model;
@property (nonatomic, strong) NSString *current_language_model;
@property (nonatomic, strong) NSString *current_dictionary;
@property (nonatomic, strong) NSString *path_to_dynamic_language_model;
@property (nonatomic, strong) NSString *path_to_dynamic_grammar;


// Language Model Generator
- (void)generateLanguageModel:(CDVInvokedUrlCommand*)command;

// PocketSphinx Controller
- (void)stopListening:(CDVInvokedUrlCommand*)command;
- (void)resumeListening:(CDVInvokedUrlCommand*)command;
- (void)suspendRecognition:(CDVInvokedUrlCommand*)command;
- (void)resumeRecognition:(CDVInvokedUrlCommand*)command;
- (void)startListeningWithLanguageModelAtPath:(CDVInvokedUrlCommand*)command;
- (void)changeLanguageModelToFile:(CDVInvokedUrlCommand*)command;

// Flite
- (void)say:(CDVInvokedUrlCommand*)command;

@end
