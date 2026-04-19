import React from 'react';
import Product from '../components/Product';
import { useLoaderData } from '../router/SimpleRouter';

const ProductsPage = () => {
  const { loaderData, isLoading, loaderError } = useLoaderData();

  if (isLoading) {
    return (
      <section className="page-card">
        <h2>Products</h2>
        <p className="status-text">Loading products from details.json...</p>
      </section>
    );
  }

  if (loaderError) {
    return (
      <section className="page-card">
        <h2>Products</h2>
        <p className="status-text error-text">Loader error: {loaderError}</p>
      </section>
    );
  }

  const products = Array.isArray(loaderData) ? loaderData : [];

  return (
    <section className="page-card">
      <div className="page-head">
        <h2>Products</h2>
        <span className="count-badge">{products.length} cards</span>
      </div>

      {products.length === 0 ? (
        <p className="status-text">No products in JSON.</p>
      ) : (
        <div className="products-grid">
          {products.map((item) => (
            <Product key={item.id} item={item} />
          ))}
        </div>
      )}
    </section>
  );
};

export default ProductsPage;
