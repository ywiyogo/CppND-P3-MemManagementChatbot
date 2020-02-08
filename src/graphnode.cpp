#include "graphnode.h"
#include "graphedge.h"
GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // Task 0: There is no memory allocation in this class for _chatBot. Thus
    // deleting the pointer is incorrect
    // delete _chatBot;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(int id)
{
    std::unique_ptr<GraphEdge> childEdge = std::make_unique<GraphEdge>(id);
    _childEdges.push_back(std::move(childEdge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    // use move constructor
    _chatBot = std::move(chatbot);
    // send selected node answer to user
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode* newNode)
{
    // use move assignment operator
    newNode->MoveChatbotHere(std::move(_chatBot));
}

GraphEdge* GraphNode::GetChildEdge(int id)
{
    GraphEdge* result = nullptr;
    for (auto const& edge : _childEdges)
    {
        if (edge->GetID() == id)
        {
            result = edge.get();
            break;
        }
    }
    return result;
}

////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
