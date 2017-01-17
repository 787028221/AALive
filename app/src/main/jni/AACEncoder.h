#pragma once
extern "C" {
#include <libavformat\avformat.h>
#include <libavutil/opt.h>
#include <libavcodec/avcodec.h>
#include <libavutil/channel_layout.h>
#include <libavutil/common.h>
#include <libavutil/imgutils.h>
#include <libavutil/mathematics.h>
#include <libavutil/samplefmt.h>
}
#ifndef __AA_AAC_ENCODER_H
#define __AA_AAC_ENCODER_H

class AACEncoder {
public:
	AACEncoder();
	~AACEncoder();
	void setSampleRate(int sampleRate) {
		mSampleRate = sampleRate;
	}
	void setChannelNumber(int channelNumber) {
		mChannelNumber = channelNumber;
	}
	void setBytePerSample(int bytesPerSample) {
		mBytesPerSample = bytesPerSample;
	}
	void setBitrate(int biterate) {
		mBitrate = biterate;
	}
	bool encode(AVPacket *avpkt, const AVFrame *srcFrame);
    void release();

private:
    bool init();
	int mSampleRate;
	int mChannelNumber;
	int mBytesPerSample;
	int mBitrate;
	AVCodecContext *mCodecContext;
};

#endif