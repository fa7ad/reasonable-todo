open StoreProvider;

module MyApp = {
  [@react.component]
  let make = () => {
    let (state, dispatch) =
      React.useReducer(StoreContext.reducer, {ui: Black});

    <Dispatch value=dispatch>
      <Store value=state>
        <App />
      </Store>
    </Dispatch>;
  };
};

ReactDOMRe.renderToElementWithId(<MyApp />, "app");