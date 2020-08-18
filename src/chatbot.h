#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <iostream>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);
    
    static int _count;

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    ChatBot(ChatBot &);
    ChatBot(ChatBot &&);
    
    // Copy operator with shared policy
    ChatBot &operator=(ChatBot &that) {
      std::cout << "ChatBot Copy Operator" << std::endl;
      _currentNode = that._currentNode;
      _rootNode = that._rootNode;
      _chatLogic = that._chatLogic;
      _image = that._image;
  
      _count ++;
  
      return *this;
     }
     
    // Move operator
    ChatBot &operator=(ChatBot &&that) {
      std::cout << "ChatBot Move Operator" << std::endl;
      _currentNode = that._currentNode;
      _rootNode = that._rootNode;
      _chatLogic = that._chatLogic;
      _image = that._image;
  
      that._currentNode = nullptr;
      that._rootNode = nullptr;
      that._chatLogic = nullptr;
      that._image = nullptr;
  
      return *this;
    }
     
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */