#include <node.h>
#include <v8.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <decodeqr.h>

using namespace v8;

Handle<Value> Method(const Arguments& args) {
    HandleScope scope;
    const char *retValue;
    //const char *c_arg;

    if (args.Length() < 1) {
    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
    return scope.Close(Undefined());
    }

    String::Utf8Value param1(args[0]->ToString());
    std::string from = std::string(*param1);

    try {
        IplImage *src=cvLoadImage(from.c_str(),1);
        QrDecoderHandle decoder=qr_decoder_open();
        short stat=qr_decoder_decode_image(decoder,src);

        QrCodeHeader header;
        if(qr_decoder_get_header(decoder,&header)){
            retValue=new char[header.byte_size+1];
            qr_decoder_get_body(decoder,(unsigned char *)retValue,header.byte_size+1);
        }

        qr_decoder_close(decoder);
        cvReleaseImage(&src);
    }catch(cv::Exception& e) {
        ThrowException(Exception::Error(String::New("Cannot decode image")));
        return scope.Close(Undefined());
    }  

    return scope.Close(String::New(retValue));
}

void init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("decode"), FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(decode, init)