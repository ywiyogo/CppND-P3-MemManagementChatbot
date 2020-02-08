#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <memory>
class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    std::unique_ptr<wxBitmap> _image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    //Implement the RULE of 5
    // 2 : Copy constructor
    ChatBot(const ChatBot &filename);
    // 3 : copy assignment operator
    ChatBot &operator=(const ChatBot &source);
    ChatBot &operator=(const std::unique_ptr<ChatBot> &source);
    // 4 : move constructor
    ChatBot(ChatBot &&source);
    // Move assignment operator
    ChatBot &operator=(ChatBot &&source);
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image.get(); }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */