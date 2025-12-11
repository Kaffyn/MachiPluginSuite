#include "sound_server.h"

SoundServer *SoundServer::singleton = nullptr;

void SoundServer::_bind_methods() {
    // expose methods
}

SoundServer *SoundServer::get_singleton() {
	return singleton;
}

SoundServer::SoundServer() {
	singleton = this;
}

SoundServer::~SoundServer() {
	if (singleton == this) {
		singleton = nullptr;
	}
}

void SoundServer::play_global_cue(const Ref<Resource> &p_cue) {
    // Logic to delegate to default listener or manager?
    // Usually SoundServer manages data/config, SoundManager(Node) manages playback in tree.
}
